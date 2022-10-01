# Remote-Stethoscope

## Communication
https://discord.gg/FuhREH3RJC  
https://discord.gg/3YbG3uJR

## Data Pipeline 
- Heart
- Microphone
  - filter input frequency range
    - what frequency ranges are of interest?
    - do we want a discrete or analog UI for controlling inputs on the stethoscope?
  - amplify signal if analog mic
  - convert to digital signal if not a digital mic
  - potentially explore using multiple types of microphones and use input concensus to further filter out noise
- microcontroller processes raw input into audio format
- microcontroller streams unencrypted data to PC as a microphone
- PC software encrypts audio stream and sends to doctor in real-time
  - PC software on doctor's end decrypts audio stream and broadcasts to system audio output
- PC software (on user end or doctor's end?) saves an encrypted copy of the recording as an audio file (and sends it to doctor if on user's end)
  - Advantages of user's end file save:
    - Potential for packet loss of done on doctor's end
  - Advantages of doctor's end file save:
    - Doctor can segment the incoming real-time stream based on when the patient switches which body part is being listened to, allowing for an easier time with labeling the saved data for potential data visualization and AI applications
