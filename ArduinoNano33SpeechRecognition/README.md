# Arduino Nano 33 BLE Sense Speech Recognition

### This tutorial is based what Shawn Hymel from Digi-Key did but (in my opinion) simplified and reordered a bit for my write up. Any video clips you see are from his original video and all the scripts/py files belong to him unless otherwise noted.


## Guide
### Tooling And Necessary Files 
Download the latest version of python with pip (currently 3.9.5) </br>
https://www.python.org/downloads </br>
Open up your shell of choice/the command line (For Windows I recommend Windows PowerShell or Command Prompt and avoiding Git Bash as that runs into some issues) and download numpy, librosa, and soundfile by run the following: 
```python -m pip install librosa numpy soundfile``` </br>
Now that we have all the tooling we need lets move onto some other files we must aquire. </br>

[Shawn Hymel Repo for python scripts][reference link2]

[Google Speech Commands dataset.][reference link]

The above two links will get you the following:
```
ei-keyword-spotting-master (unzipped)

data_speech_commands_v0.02.tar.gz (a lot of files don’t unzip yet)
 ``` 
### Setting Up Our Folder Structure
Now make 4 folders (the first one is going to have 2 subfolders):
```
datasets
  data_speech_commands
  custom_keywords

speech-recognition
```
Best place to put them is in your documents </br>
C:\Users\ *\*Admin/your name\** \Documents </br>


Now from ei-keyword-spotting-master take the two .py files and move them into the “speech-recognition” folder (dataset-curation.py and utils.py)
```
datasets
  data_speech_commands
  custom_keywords

speech-recognition
  dataset-curation.py 
  utils.py
```

Extract data_speech_commands_v0.02.tar.gz into the “data_speech_commands” subfolder you may need to extract twice. </br>
Now take “_background_noise_” and move it into the “datasets” parent folder 

Your file structure should look like this:
```
datasets
  data_speech_commands
  custom_keywords
  _background_noise_
 
 speech-recognition
  dataset-curation.py 
  utils.py
```

### Creating Your Custom Keyword For Recognition
In order to create your own custom keyword you’re going to need [Audacity][reference link3] and to create a new folder: </br>
Within the custom_keywords directory create a new folder that is the name of your custom keyword/phrase (don’t use “_” it will mess up the script we will be using later) </br>

You’re going to need to record yourself saying your keyword a bunch of times. </br>

Using your phone/camera mic say a chosen keyword or phrase for 1 second (varying pitch, tone, inflection, etc) and shoot for around (min 50 samples) (100 samples to be safe) (couple 100 samples if you have time) (and if you really want to develop this with some robustness around 1000 samples is a good stopping point). This is going to be the base of the data we train our model with. This unfortunately means our model is going to be really good at recognizing our voice but not much good with recognizing other’s voices. In an ideal world you would collect samples from various people with different sounding voices to better train your model but for the sake of this sample using only your voice and with a few samples should serve its purpose. See short video below for full walkthrough.

<a href="https://youtu.be/bxQ29mNKYww" target="_blank"><img src="http://img.youtube.com/vi/bxQ29mNKYww/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a> </br>

### Running The Python Script
Here is a video showing you how to run the script as well as a detailed written description: </br>
<a href="https://youtu.be/CjSUhOtDkTw" target="_blank"><img src="http://img.youtube.com/vi/CjSUhOtDkTw/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a> </br>

Use your shell to navigate to the speech-recognition folder (where the python files are) </br>
And run the “dataset-curation.py” file
``` 
python dataset-curation.py -t "*keyword1 , keyword2, etc*" -n 1500 -w 1.0 -g 0.1 -s 1.0 -r 16000 -e PCM_16 -b "*path to _background_noise_*" -o "*path to dataset folder*\keywords_curated" "*path to data_speech_commands*" "*path to custom_keywords folder*"
 ```
 
More detailed breakdown here:
```
python dataset-curation.py 
-t "keyword1, keyword2, ..., etc" 
-n 1500 (output samples per label)
-w 1.0  (utterance volume)
-g 0.1  (background noise volume)
-s 1.0  (sample time )
-r 16000  (sample rate)
-e PCM_16 (bit depth)

// path to _backgroung_noise_
 -b "C:\Users\rickr\Documents\datasets\_background_noise_"
 
// output directory (will create new file)
-o "C:\Users\rickr\Documents\datasets\keywords_cureated"

// these two links are path to input dir containing raw audio samples
"C:\Users\rickr\Documents\datasets\data_speech_commands" "C:\Users\rickr\Documents\datasets\custom_keywords"
```

Example full call I did:
```
python dataset-curation.py -t "kirchoffslaw, dog" -n 1500 -w 1.0 -g 0.1 -s 1.0 -r 16000 -e PCM_16 -b "C:\Users\rickr\Documents\datasets\_background_noise_" -o "C:\Users\rickr\Documents\datasets\keywords_cureated" "C:\Users\rickr\Documents\datasets\data_speech_commands" "C:\Users\rickr\Documents\datasets\custom_keywords"
```

### Edge Impulse 
<a href="https://youtu.be/fRSVQ4Fkwjc?t=619" target="_blank"><img src="http://img.youtube.com/vi/fRSVQ4Fkwjc/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a> </br>
Watch the ending of this video for instructions on how to finish creating your neural network </br>

The platform.local.txt mentioned in the video for the Arduino upload error is located in this repo


If you would rather watch the full guide from Shawn Hymel here is the [link][reference link4] </br>
It's a great video but I personally ran into a few glitch/errors and did my best to correct them with this guide. Regardless Shawn Hymel does a great job at explaining things.

## Credits
https://www.youtube.com/watch?v=fRSVQ4Fkwjc&ab_channel=Digi-Key </br>  
https://github.com/ShawnHymel/ei-keyword-spotting


[reference link]: https://storage.cloud.google.com/download.tensorflow.org/data/speech_commands_v0.02.tar.gz

[reference link2]: https://github.com/ShawnHymel/ei-keyword-spotting
[reference link3]:  https://www.audacityteam.org/download
[reference link4]:  https://www.youtube.com/watch?v=fRSVQ4Fkwjc&ab_channel=Digi-Key

