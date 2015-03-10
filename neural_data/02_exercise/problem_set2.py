#
#  NAME
#    problem_set2_solutions.py
#
#  DESCRIPTION
#    Open, view, and analyze action potentials recorded during a behavioral
#    task.  In Problem Set 2, you will write create and test your own code to
#    create tuning curves.
#

#Helper code to import some functions we will use
import numpy as np
import matplotlib.pylab as plt
import matplotlib.mlab as mlab
from scipy import optimize
from scipy import stats


def load_experiment(filename):
    """
    load_experiment takes the file name and reads in the data.  It returns a
    two-dimensional array, with the first column containing the direction of
    motion for the trial, and the second column giving you the time the
    animal began movement during thaht trial.
    """
    data = np.load(filename)[()];
    return np.array(data)

def load_neuraldata(filename):
    """
    load_neuraldata takes the file name and reads in the data for that neuron.
    It returns an arary of spike times.
    """
    data = np.load(filename)[()];
    return np.array(data)
    
def bin_spikes(trials, spk_times, time_bin):
    """
    bin_spikes takes the trials array (with directions and times) and the spk_times
    array with spike times and returns the average firing rate for each of the
    eight directions of motion, as calculated within a time_bin before and after
    the trial time (time_bin should be given in seconds).  For example,
    time_bin = .1 will count the spikes from 100ms before to 100ms after the 
    trial began.
    
    dir_rates should be an 8x2 array with the first column containing the directions
    (in degrees from 0-360) and the second column containing the average firing rate
    for each direction
    """
    directions = np.unique(trials[:,0]) # Prints the directions
    spikes_per_direction = np.zeros(directions.size)
    trials_per_direction = np.zeros(directions.size)

    spikes_per_trial = np.zeros(trials.shape[0])

    # Get the number of spikes that correspond to each trial
    for index, trial_time in enumerate(trials[:,1]):
        aux1 = spk_times < trial_time + time_bin  
        aux2 = spk_times > trial_time - time_bin
        spikes_per_trial[index] = np.sum(np.logical_and(aux1, aux2)) # Get the number of spikes in [trial_time - time_bin, trial_time + time_bin]

    # Get the number of spikes and number of trial per direction 
    for i, direction in enumerate(directions):
        for index, trial_direction in enumerate(trials[:,0]):
            if direction == trial_direction:
                spikes_per_direction[i] += spikes_per_trial[index]
                trials_per_direction[i] += 1

    firing_rates = spikes_per_direction / (trials_per_direction * 2 * time_bin) # Number of spikes / (number of trials  * time it took to measure them)
    dir_rates = np.column_stack([directions, firing_rates])

    return dir_rates
    
def plot_tuning_curves(direction_rates, title):
    """
    This function takes the x-values and the y-values  in units of spikes/s 
    (found in the two columns of direction_rates) and plots a histogram and 
    polar representation of the tuning curve. It adds the given title.
    """
    firing_rate = direction_rates[:, 1]
    label = 'Firing Rate (spikes/s)'
    max_firing_rate = np.max(firing_rate)
    
    plt.subplot(1, 2, 1)
    plt.bar(direction_rates[:,0], firing_rate, width=45)
    plt.xlabel('Direction (degrees)')
    plt.ylabel(label)
    plt.title(title)
    plt.axis([0, 360, 0, max_firing_rate*1.1])

    plt.subplot(1, 2, 2, polar=True)
    theta = np.deg2rad(direction_rates[:, 0]) # Transform to radians 
    theta = np.append(theta, 0) # Append a zero
    r = np.append(firing_rate, firing_rate[0]) # Append first value at the end
    plt.polar(theta, r, label=label)
    plt.title(title)
    plt.legend(loc=8)

    plt.show()
    
def roll_axes(direction_rates):
    """
    roll_axes takes the x-values (directions) and y-values (direction_rates)
    and return new x and y values that have been "rolled" to put the maximum
    direction_rate in the center of the curve. The first and last y-value in the
    returned list should be set to be the same. (See problem set directions)
    Hint: Use np.roll()
    """

    angles = direction_rates[:,0] # Take out the angles 
    firing_rates = direction_rates[:,1]  # Take out the firing rates 

    roll_degrees = angles[np.argmax(firing_rates)]

    angles = np.append(angles, 360) - roll_degrees

    firing_rates = np.append(firing_rates, firing_rates[-1])

    
    points_per_grad = angles.size / ( np.abs(angles[-1] - angles[0]) ) 
    firing_rates = np.roll(firing_rates, int(roll_degrees * points_per_grad))

    new_xs = angles
    new_ys = firing_rates
    

    return new_xs, new_ys, roll_degrees    
    

def normal_fit(x, mu, sigma, A):
    """
    This creates a normal curve over the values in x with mean mu and
    variance sigma.  It is scaled up to height A.
    """
    n = A*mlab.normpdf(x,mu,sigma)
    return n

def fit_tuning_curve(centered_x, centered_y):
    """
    This takes our rolled curve, generates the guesses for the fit function,
    and runs the fit.  It returns the parameters to generate the curve.
    """
    max_y = np.max(centered_y)
    max_x = centered_x[np.argmax(max_y)]
    sigma = 90

    p, cov = optimize.curve_fit(normal_fit, centered_x, centered_y, p0=[max_x, sigma, max_y])
    
    return p
    


def plot_fits(direction_rates, fit_curve, title1, title2):
    """
    This function takes the x-values and the y-values  in units of spikes/s 
    (found in the two columns of direction_rates and fit_curve) and plots the 
    actual values with circles, and the curves as lines in both linear and 
    polar plots.
    """

    firing_rate = direction_rates[:, 1]
    label = 'Firing Rate (spikes/s)'

    max_firing_rate = np.max(firing_rate)

    plt.subplot(2, 2, 1)
    plt.bar(direction_rates[:,0], firing_rate, width=45)
    plt.xlabel('Direction of Motion (degrees)')
    plt.ylabel(label)
    plt.title(title1)
    plt.axis([0, 360, 0, max_firing_rate*1.1])

    plt.subplot(2, 2, 2, polar=True)
    theta = np.deg2rad(direction_rates[:, 0]) # Transform to radians 
    theta = np.append(theta, 0) # Append a zero
    r = np.append(firing_rate, firing_rate[0]) # Append first value at the end
    plt.polar(theta, r, label=label)
    plt.title(title1)
    plt.legend(loc=8)


    plt.subplot(2, 2, 3)
    plt.plot(direction_rates[:,0], direction_rates[:,1], 'o')
    plt.plot(fit_curve[:,0], fit_curve[:,1])
    plt.xlabel('Direction of Motion (degrees)')
    plt.ylabel(label)
    plt.title(title2)
    plt.axis([0, 360, 0, max_firing_rate*1.1])

    plt.subplot(2, 2, 4, polar=True)

    theta = np.deg2rad(direction_rates[:, 0]) # Transform to radians 
    theta = np.append(theta, 0) # Append a zero
    r = np.append(firing_rate, firing_rate[0]) # Append first value at the end
    plt.polar(theta, r,'o')

    theta = np.deg2rad(fit_curve[:, 0]) # Transform to radians 
    theta = np.append(theta, 0) # Append a zero
    r = np.append(fit_curve[:, 1], fit_curve[-1,1]) # Append first value at the end
    plt.polar(theta, r, label=label)

    
    plt.title(title2)
    plt.legend(loc=8)

    plt.show()

    

def von_mises_fitfunc(x, A, kappa, l, s):
    """
    This creates a scaled Von Mises distrubition.
    """
    return A*stats.vonmises.pdf(x, kappa, loc=l, scale=s)


    
def preferred_direction(fit_curve):
    """
    The function takes a 2-dimensional array with the x-values of the fit curve
    in the first column and the y-values of the fit curve in the second.  
    It returns the preferred direction of the neuron (in degrees).
    """
    
    
    return pd
    
        
##########################
#You can put the code that calls the above functions down here    
if __name__ == "__main__":
    time_bin = 0.1
    title = 'Example Neuron Tuning Curve'
    trials = load_experiment('trials.npy')   
    spk_times = load_neuraldata('neuron3.npy') 
    direction_rates = bin_spikes(trials, spk_times, time_bin)
    if False:
        plot_tuning_curves(direction_rates, title)
    
    centered_x, centered_y, roll_degrees = roll_axes(direction_rates)
    p = fit_tuning_curve(centered_x, centered_y)

    curve_x = np.arange(centered_x[0], centered_x[-1])
    fit_ys = normal_fit(curve_x, p[0],p[1],p[2])

    if False:
        plt.plot(centered_x, centered_y, '*')
        plt.plot(curve_x, fit_ys)
        plt.show()
    
    

    final_x = curve_x + roll_degrees
    points_per_grad = final_x.size / ( np.abs(centered_x[-1] - centered_x[0]) ) 
    final_fit = np.roll(fit_ys, -int(roll_degrees * points_per_grad)) # Move ahead(-1) as many points as they are in 90 degrees 
    
    fit_curve = np.column_stack([final_x, final_fit])

    prefered_direction = final_x[np.argmax(final_fit)]
#plot fits
if True:
    title1 = title
    title2 = 'Example of Tunning Curve - Fit'
    plot_fits(direction_rates, fit_curve, title1, title2)


