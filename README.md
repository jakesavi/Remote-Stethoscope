# Remote-Stethoscope

## Communication
https://discord.gg/RNJMYp4RQn

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

## Getting Started
1. Connect the Xiao RP2040 to your computer via USB-C cable
    - In order to boot the microcontroller into flashable mode, hold down the microcontroller push button labeled "B" from before the connection to the computer happens until after the LED on the microcontroller turns on.
2. To flash a new microcontroller with the software to act as a microphone, copy the file usb_microphone.uf2 into the root directory of the microcontroller.  It should automatically disconnect after this and reboot into a device that the system will refer to as MicNode
3. Connect the Xiao RP2040 to the MEMS digital microphone.  See "./Fall2022 Audio Samples/EffectiveCircuit.png" for a demonstration of of how the circuit should appear.
    - The microcontroller and microphone boards should both be soldered to their respective pin headers in order for this to work.
4. Open Audacity, select Microphone (MicNode) as your recording device, begin recording, and confirm that the microphone is recording a clear signal.
