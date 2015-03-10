#
#  NAME
#    problem_set4.py
#
#  DESCRIPTION
#    In Problem Set 4, you will classify EEG data into NREM sleep stages and
#    create spectrograms and hypnograms.
#
from __future__ import division
import numpy as np
import matplotlib.pylab as plt
import matplotlib.mlab as m
from sklearn.linear_model import LinearRegression, LogisticRegression 


def load_examples(filename):
    """
    load_examples takes the file name and reads in the data.  It returns an
    array containing the 4 examples of the 4 stages in its rows (row 0 = REM;
    1 = stage 1 NREM; 2 = stage 2; 3 = stage 3 and 4) and the sampling rate for
    the data in Hz (samples per second).
    """
    data = np.load(filename)
    return data['examples'], int(data['srate'])

def load_eeg(filename):
    """
    load_eeg takes the file name and reads in the data.  It returns an
    array containing EEG data and the sampling rate for
    the data in Hz (samples per second).
    """
    data = np.load(filename)
    return data['eeg'], int(data['srate'])

def load_stages(filename):
    """
    load_stages takes the file name and reads in the stages data.  It returns an
    array containing the correct stages (one for each 30s epoch)
    """
    data = np.load(filename)
    return data['stages']


def plot_example_psds(example, rate):
    """
    This function creates a figure with 4 lines to show the overall psd for 
    the four sleep examples. (Recall row 0 is REM, rows 1-3 are NREM stages 1,
    2 and 3/4)
    """
    NFFT = 512
    rem = example[0]
    nrem_stage1 = example[1]
    nrem_stage2 = example[2]
    nrem_stage34 = example[3]

    plt.figure()
    
    ##YOUR CODE HERE    
    Pxx, freqs = m.psd(rem, NFFT=NFFT, Fs=rate)
    Pxx = Pxx / np.sum(Pxx)  # normalize 
    plt.plot(freqs, Pxx, label='rem')
    plt.hold(True)
    
    Pxx, freqs = m.psd(nrem_stage1, NFFT=NFFT, Fs=rate)
    Pxx = Pxx / np.sum(Pxx)  # normalize 
    plt.plot(freqs, Pxx, label='nrem stage 1')
    
    Pxx, freqs = m.psd(nrem_stage2, NFFT=NFFT, Fs=rate)
    Pxx = Pxx / np.sum(Pxx)  # normalize
    plt.plot(freqs, Pxx, label='nrem stage 2')

    Pxx, freqs = m.psd(nrem_stage34, NFFT=NFFT, Fs=rate)
    Pxx = Pxx / np.sum(Pxx)  # normalize
    plt.plot(freqs, Pxx, label='nrem stage 3/4')

    # Plot details 
    plt.xlim([0, 20])
    plt.legend()
    plt.show() 
        
    return

def plot_example_spectrograms(example,rate):
    """
    This function creates a figure with spectrogram sublpots to of the four
    sleep examples. (Recall row 0 is REM, rows 1-3 are NREM stages 1,
    2 and 3/4)
    """

    NFFT = 2**8
    rem = example[0]
    nrem_stage1 = example[1]
    nrem_stage2 = example[2]
    nrem_stage34 = example[3]
    
    plt.figure()
    plt.hold(True)
    
    ###YOUR CODE HERE
    plt.subplot(2, 2, 1)
    Pxx, freqs, bins, im  = plt.specgram(rem, NFFT=NFFT, Fs=rate)
    plt.title('Rem Sleep')
    plt.ylim((0,30))
    plt.xlabel('Time')
    plt.ylabel('Frequency')

    plt.subplot(2, 2, 2)
    Pxx, freqs, bins, im  = plt.specgram(nrem_stage1, NFFT=NFFT, Fs=rate)
    plt.title('Non-rem stage 1')
    plt.ylim((0,30))
    plt.xlabel('Time')
    plt.ylabel('Frequency')


    plt.subplot(2, 2, 3)
    Pxx, freqs, bins, im  = plt.specgram(nrem_stage2, NFFT=NFFT, Fs=rate)
    plt.title('Non-rem stage 2')
    plt.ylim((0,30))
    plt.xlabel('Time')
    plt.ylabel('Frequency')


    plt.subplot(2, 2, 4)
    Pxx, freqs, bins, im  = plt.specgram(nrem_stage34, NFFT=NFFT, Fs=rate)
    plt.title('Non-rem stage 3/4')
    plt.ylim((0,30))
    plt.xlabel('Time')
    plt.ylabel('Frequency')


    
    plt.show()
#    return Pxx, freqs

def predictor():

    example_filename = 'example_stages.npz'
    examples, srate = load_examples(example_filename)

    NFFT = 2**8
    rate = srate
    number_of_features = 45
    c = 1e5


    nrem1 = examples[1]
    nrem2 = examples[2]
    nrem3 = examples[3]

    Pxx1, freqs, bins, im  = plt.specgram(nrem1, NFFT=NFFT, Fs=rate)
    Pxx2, freqs, bins, im  = plt.specgram(nrem2, NFFT=NFFT, Fs=rate)
    Pxx3, freqs, bins, im  = plt.specgram(nrem3, NFFT=NFFT, Fs=rate)
    plt.show()

    Normalize = False
    # Normalize
    if Normalize:
        sum = np.sum(Pxx1, axis=1)
        Pxx1 = Pxx1 / sum[:,np.newaxis]

        sum = np.sum(Pxx2, axis=1)
        Pxx2 = Pxx2 / sum[:,np.newaxis]

        sum = np.sum(Pxx3, axis=1)
        Pxx3 = Pxx3 / sum[:,np.newaxis]
    

    x1 = np.arange(0,8)
    x2 = np.arange(10,15)
    x4 = np.concatenate((x1,x2))

    x4 = np.arange(0,15)
    
    if True:
        Pxx1 = Pxx1[0:number_of_features, :]
        Pxx2 = Pxx2[0:number_of_features, :]
        Pxx3 = Pxx3[0:number_of_features, :]

    if False:
        Pxx1 = Pxx1[x4, :]
        Pxx2 = Pxx2[x4, :]
        Pxx3 = Pxx3[x4, :]

    value1 = 1
    value2 = 2
    value3 = 3

    y1 = np.ones(Pxx1.shape[1]) * value1
    y2 = np.ones(Pxx2.shape[1]) * value2
    y3 = np.ones(Pxx3.shape[1]) * value3


    x = np.hstack([Pxx1, Pxx2, Pxx3])
    x = x.transpose()
    y = np.hstack([y1, y2, y3])


    lr = LogisticRegression(C=c, penalty='l1')
    lr.fit(x, y)
    
    return lr
    

def classify_epoch(epoch , rate, lr):
    """
    This function returns a sleep stage classification (integers: 1 for NREM
    stage 1, 2 for NREM stage 2, and 3 for NREM stage 3/4) given an epoch of 
    EEG and a sampling rate.
    """

    NFFT = 2**8
    Pxx, freqs = m.psd(epoch, NFFT=NFFT, Fs=rate)

    p = map(lr.predict, Pxx[np.newaxis,0:45])
    p = np.array(p)
    p = p[:,0] 

    stage = int(p)
    ###YOUR CODE HERE
    return stage

def plot_hypnogram(eeg, stages, srate, title):
    """
    This function takes the eeg, the stages and sampling rate and draws a 
    hypnogram over the spectrogram of the data.
    """
    NFFT = 2**8
    
    fig,ax1 = plt.subplots()  #Needed for the multiple y-axes
    
    #Use the specgram function to draw the spectrogram as usual
    Pxx, freqs, bins, im  = plt.specgram(eeg, NFFT=NFFT, Fs=srate)
    #Label your x and y axes and set the y limits for the spectrogram
    plt.ylim((0,30))
    plt.xlim((0,3600))
    plt.xlabel('Time (seconds)')
    plt.ylabel('Frequency (Hz)')

    
    ax2 = ax1.twinx() #Necessary for multiple y-axes


    #Use ax2.plot to draw the hypnogram.  Be sure your x values are in seconds
    #HINT: Use drawstyle='steps' to allow step functions in your plot
    t = np.arange(0, stages.size) * 30
    ax2.plot(t, stages, drawstyle='steps')
    #Label your right y-axis and change the text color to match your plot
    ax2.set_ylabel('NREM Sleep Stage',color='b')

    plt.xlim((0,3600))

 
    #Set the limits for the y-axis
    plt.ylim((0.5,3.5))
 
    #Only display the possible values for the stages
    ax2.set_yticks(np.arange(1,4))
    
    #Change the left axis tick color to match your plot
    for t1 in ax2.get_yticklabels():
        t1.set_color('b')
    
    #Title your plot    
    plt.title(title)
  

        
def classifier_tester(classifiedEEG, actualEEG):
    """
    returns percent of 30s epochs correctly classified
    """
    epochs = len(classifiedEEG)
    incorrect = np.nonzero(classifiedEEG-actualEEG)[0]
    percorrect = (epochs - len(incorrect))/epochs*100
    
    print 'EEG Classifier Performance: '
    print '     Correct Epochs = ' + str(epochs-len(incorrect))
    print '     Incorrect Epochs = ' + str(len(incorrect))
    print '     Percent Correct= ' + str(percorrect) 
    print 
    return percorrect
  
    
def test_examples(examples, srate, lr):
    """
    This is one example of how you might write the code to test the provided 
    examples.
    """
    i = 0
    bin_size = int(30*srate)
    c = np.zeros((4,int(len(examples[1,:])/bin_size)))
    while i + bin_size < len(examples[1,:]):
        for j in range(1,4):
            c[j,int(i/bin_size)] = classify_epoch(examples[j, range(i,i+bin_size)],srate, lr)
        i = i + bin_size
    
    totalcorrect = 0
    num_examples = 0
    for j in range(1,4):
        canswers = np.ones(len(c[j,:]))*j
        correct = classifier_tester(c[j,:],canswers)
        totalcorrect = totalcorrect + correct
        num_examples = num_examples + 1
    
    average_percent_correct = totalcorrect/num_examples
    print 'Average Percent Correct= ' + str(average_percent_correct) 
    return average_percent_correct

def classify_eeg(eeg,srate, lr):
    """
    DO NOT MODIFY THIS FUNCTION
    classify_eeg takes an array of eeg amplitude values and a sampling rate and 
    breaks it into 30s epochs for classification with the classify_epoch function.
    It returns an array of the classified stages.
    """
    bin_size_sec = 30
    bin_size_samp = int(bin_size_sec*srate)
    t = 0
    classified = np.zeros(int(len(eeg)/bin_size_samp))
    while t + bin_size_samp < len(eeg):
       classified[int(t/bin_size_samp)] = classify_epoch(eeg[range(t,t+bin_size_samp)],srate, lr)
       t = t + bin_size_samp
    return classified



        
##########################
#You can put the code that calls the above functions down here    
if __name__ == "__main__":
    #YOUR CODE HERE

    plt.close('all') #Closes old plots
    ##PART 1
    #Load the example data
    example_filename = 'example_stages.npz'
    examples, srate = load_examples(example_filename)

    #Plot the psds
    #plot_example_psds(examples, srate)

    #Plot the spectrograms
    #plot_example_spectrograms(examples, srate)

    # predictor
    lr = predictor()
    
    #Test the examples
    #test_examples(examples, srate, lr)
    
    #Load the practice data
    practice_eeg, srate = load_eeg('practice_eeg.npz')
    #Load the practice answersp
    practice_stages = load_stages('practice_answers.npz')
    #Classify the practice data
    #classified = classify_eeg(practice_eeg ,srate, lr)
    #Check your performance
    #classifier_tester(classified, practice_stages)
    #Generate the hypnogram plots
    eeg, srate = load_eeg('test_eeg.npz')
    stages = classify_eeg(eeg, srate, lr)
    #plot hynporgram
    #plot_hypnogram(eeg, stages, srate, 'Hypnogram - Test Data Set')
    plot_hypnogram(practice_eeg, practice_stages, srate, 'Hynpogram - Practice Data Set')
    plt.show()

    if False:
        plot_hypnogram(practice_eeg, classified, srate, 'mine')
        plt.show()
        plot_hypnogram(practice_eeg, practice_stages, srate, 'correct')
        plt.show()
    


