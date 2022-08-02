import sounddevice as sd
from scipy.io import wavfile
from scipy.io.wavfile import write
from scipy.io.wavfile import read
import wavio as wv
import matplotlib.pyplot as plt
import numpy as np
import scipy.io.wavfile
import scipy.signal
from datetime import datetime
ID=str(input("Enter Participant ID: "))
io=str(input("Enter (i) if you are inside the lab; else type(o) if you are outside: "))
now = datetime.now()
current_time = str(now.strftime("%H-%M-%S"))
freq = 1500
if (io=='i'):
    duration = 660
elif (io=='o'):
    duration=900
print("Current Time =", current_time)
fname=ID+io+current_time+".wav"
recording = sd.rec(int(duration * freq),
				samplerate = freq, channels = 1)
sd.wait()
write(fname, freq, recording)
now1 = datetime.now()
current_time1 = now1.strftime("%H-%M-%S")
print("Current Time =", current_time1)
sampleRate, data = scipy.io.wavfile.read(fname)
times = np.arange(len(data))/sampleRate
plt.plot(times, data)
plt.title("Signal")
plt.margins(0, .05)
plt.setp(plt.gca(),ylim=(-1,1),xlim=(1,duration))
plt.tight_layout()
plt.show()
