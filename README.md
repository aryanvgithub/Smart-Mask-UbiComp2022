# Smart-Mask-UbiComp2022
![Flow](https://user-images.githubusercontent.com/72281283/175951848-fc6a9e0c-e6aa-4ac6-a8cd-72dcd5f1d91f.png)
<br><br>
# Data Collection<br>
To evaluate our approach we conducted a pilot study with 10 participants in the age group of 20-30 years. The cohort included 2 female participants. Each participant was given a fresh N95 mask. One of the investigator fixed the sensor inside the mask using neodymium magnet. The sensing system consisted of the CO2 sensor and the audio (Wireless earbud) sensor. We curated a data collection check list to ensure uniform data collection procedure across all participants. The data collection lasted for about 45 minutes. It started with the participant sitting indoor in a  chair. The timeline for each participant in the indoor experiment are as follows: 
- Before experiment: We ensured that both the CO2 sensor and the wireless earbud audio sensor is collecting data and transferring it over BLE and Bluetooth 5, respectively.
- 0-2 Minute: The participant donned the mask during this period and continued normal breathing. In this period, we ensured that the participant is comfortable with the mask and the sensor is not hampering their normal activity. We did not use the data from this period for our analysis.
- 2-5 Minute: In this period we asked the participant to perform breathing with a 30 Beat Per Minute (BPM) metronome. The metronome beat was played via a speaker. This was done to check if the respiratory rate is consistent with the metronome.
- 5-11 Minute: During this period, the participant continued normal breathing without the metronome. We asked the participant to perform a forceful exhalation akin to spirometry at the start of 8th minute. In this preliminary work, we did not investigate the forced breathing signal. 

Outdoor data collection followed the indoor one after a gap of about 5-10 minutes. The outdoor experiment mainly consisted of participant wearing the mask and performing a 6 Minute Walk Test. Our objective was to determine if respiratory rate can be deduced when the person is walking and if so, to record the changes in observation during and after the walk. The following timeline was followed for outdoor data collection.
- 0-2 Minute: Similar to the indoor experiment, in this phase we ensured that the participant is comfortable by wearing the mask and the sensor inside the mask is not causing any hindrance.
- 2-8 Minute: Participant performed a 6 MWT.
- 8-11 Minute: The participant was asked to rest by sitting in a chair post the 6 MWT.
- 11-13 Minutes: The participant was asked to read out a text by wearing the mask. In this work, we did not analyze any signal recorded during the speaking phase.
- 13-15 Minute: The participant continued normal breathing with the mask donned. 
<br><br>
# Discrepancy observed with Metronome
![wrong-metronome_page-0001](https://user-images.githubusercontent.com/72281283/182385925-edfdf98c-c318-4d43-9ac2-d15a5d6f8411.jpg)
We asked participants to follow a 15 exhalation metronome, but the above image shows 13 exhalations. Hence, metronome cannot always be used for ground truth
<br><br>
# This Repository
- The "Audio" folder contains a complete guide to replicate the audio system to collect the ground truth.
- The "CO2" folder contains a complete guide to replicate the CO2 data collection system.
- The "Li-ion battery charger" contains a complete guide to replicate the Li-ion batteruy charger.
- The "Data Collection" folder compiles the complete dateset used for evaluation of this prototype.
- "Data Collection Guide" contains a complete guide to collect the data.
