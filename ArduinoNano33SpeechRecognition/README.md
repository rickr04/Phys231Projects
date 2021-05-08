# Arduino Nano 33 BLE Sense Speech Recognition

### This tutorial is based what Shawn Hymel from Digi-Key did but (in my opinion) simplified and reordered a bit. Any video clips you see are from his original video and all the scripts/py files belong to him.


## Guide
### Tooling And Necessary Files 
Download the latest version of python with pip (currently 3.9.5) </br>
https://www.python.org/downloads </br>
Open up your shell of choice/the command line (Gitbash runs into some issues so I recommend not using that) and download numpy, librosa, and soundfile by run the following: 
```python -m pip install librosa numpy soundfile``` </br>
Now that we have all the tooling we need lets move onto some other files we must aquire. </br>

[Shawn Hymel Repo for python scripts][reference link2]

[Google Speech Commnads dataset.][reference link]

The above two links will get you the following:
```
ei-keyword-spotting-master (unzipped)

data_speech_commands_v0.02.tar.gz (a lot of files don’t unzip yet)
 ``` 
Now make 4 folders (the first one is going to have 2 subfolders):
```
datasets
  data_speech_commands
  custom_keywords

speech-recognition
```
Best place to put them is in your documents </br>
C:\Users\ *\*Admin/your name\** \Documents </br>
If you’re using mac good luck lol  </br>

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

Your file struecture should look like this:
```
datasets
  data_speech_commands
  custom_keywords
  _background_noise_
 
 speech-recognition
  dataset-curation.py 
  utils.py
```
In order to create your own custom keyword you’re going to need [Audacity][reference link3] and to create a new folder: </br>
Within the custom_keywords directory create a new folder that is the name of your custom keyword/phrase (don’t use “_” it will mess up the script we will be using later) </br>

You’re going to need to record yourself saying your keyword a bunch of times. </br>

Using your phone/camera mic say a chosen keyword or phrase for 1 second (varying pitch, tone, inflection, etc) and shoot for around (min 50 samples) (100 samples to be safe) (couple 100 samples if you have time) (and if you really want to develop this with some robustness around 1000 samples is a good stopping point). This is going to be the base of the data we train our model with. This unfronlu means our model is going to really good at recognizing our voice but not much good with recogniztiing other’s voices. In an ideal world you would collect samples from various people with different sounding voices to better train your model but for the sake of this sample using only your voice and with a few samples should serve its purpose.  

[![RIP](http://img.youtube.com/vi/bxQ29mNKYww/0.jpg)](https://youtu.be/bxQ29mNKYww)


## Credits
https://www.youtube.com/watch?v=fRSVQ4Fkwjc&ab_channel=Digi-Key </br>  
https://github.com/ShawnHymel/ei-keyword-spotting

[reference link]: https://storage.cloud.google.com/download.tensorflow.org/data/speech_commands_v0.02.tar.gz

[reference link2]: https://github.com/ShawnHymel/ei-keyword-spotting
[reference link3]:  https://www.audacityteam.org/download

