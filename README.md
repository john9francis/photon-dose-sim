# Overview

Photon Dose Sim is a physics simulation of the radiation dose delivered by photons. It consists of one detector made out of water, and one particle gun that shoots 6 MeV gamma particles. 

I created this software to become familiar with Geant4 and it's organization. I also created it to get more experience modelling medical simulations.

[Software Demo Video](http://youtube.link.goes.here)

# How to run

To run this project, you must have [CMake](https://cmake.org/) installed for compiling. You also need to have the [Geant4](https://geant4.web.cern.ch/) source code installed.

Once you have the prerequisites, compile this example with CMake, then click on the executable it creates. It should automatically create a viewer and you should be able to see the square detector displayed. Then you can run the `test_run.mac` file and it will shoot some photons at the detector. It will display the dose given on the terminal window. 

# Development Environment

I developed this project in visual studio. I used CMake to compile it. 

This project is written in C++ and utilizes the Geant4 toolkit. 

# Useful Websites

- [Installing Geant4 tutorial video](https://youtu.be/w7k9PK1Ipv8)
- [Installing Geant4 with Qt visualization driver](https://youtu.be/rtCsfDD45Bc)
- [Geant4 website](https://geant4.web.cern.ch/)
- [Geant4 help for application developers](https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/index.html)
- [Geant4 forum](https://geant4-forum.web.cern.ch/)
- [CMake website](https://cmake.org/)
- [Qt website](https://www.qt.io/)

# Future Work

- Allow to save dose data to a file
- Impliment a sensitive detector to catch other particles like optical photons instead of just gamma rays
- Put some style into the look of the detector
- Make the hits on the detector display visually
- Make a more intense run, like 10^9 particles instead of just 100
- Optimize preformance, look into multithreaded mode
