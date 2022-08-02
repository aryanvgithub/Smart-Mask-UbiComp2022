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
now = datetime.now()
current_time = now.strftime("%H:%M:%S")
freq = 1500
duration = 30
print("Current Time =", current_time)
recording = sd.rec(int(duration * freq),
				samplerate = freq, channels = 1)
sd.wait()
write("File.wav", freq, recording)
now1 = datetime.now()
current_time1 = now1.strftime("%H:%M:%S")
print("Current Time =", current_time1)
sampleRate, data = scipy.io.wavfile.read('File.wav')
times = np.arange(len(data))/sampleRate
plt.plot(times, data)
plt.title("Signal")
plt.margins(0, .05)
plt.setp(plt.gca(),ylim=(-1,1),xlim=(1,30))
plt.tight_layout()
plt.show()
