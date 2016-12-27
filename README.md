# AutoMix Software

This project aims to create a virtual and intelligent DJ to help customers create their own mix so they can enjoy any music without interruption.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.  
See [deployment](#deployment) for notes on how to build and deploy the project on a live system.

### Prerequisites

This project was developed in C++ and .NET under Microsoft Visual Studio 2015. No plugins are required.

Get Visual Studio [here](https://www.visualstudio.com/downloads/).

### Installing

Clone the repository on your computer.

```
git clone https://gitlab.ecole.ensicaen.fr/stevenot/projet_2a.git
```

Open solution in Visual Studio.

```
File > Open > Project/Solution > path/to/AutoMix/Software
```

Run solution in *Debug* mode and under *x86* architecture.

----------

## Deployment

Open a command prompt for Visual Studio and navigate to the *AutoMix Software* folder in the repository.
```
msbuild /p:Configuration=Release;Architecture=x86 "AutoMix Software.sln"
```
The .exe file will be built in the *Debug* directory.

----------

## Built With

 - [Visual Studio](https://www.visualstudio.com/) - The IDE used.

----------

## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our coding style, and the process for submitting merge requests to us.

----------

## Authors

 - **Maxime STEVENOT** - *Project Manager* - <maxime.stevenot@ecole.ensicaen.fr>
 - **Guillaume HANNES** - <hannes@ecole.ensicaen.fr>
 - **Jordan ERNULT** - <ernult@ecole.ensicaen.fr>
 - **Louis CARLIER** - <lcarlier@ecole.ensicaen.fr>
 - **Pierre GABON** - <gabon@ecole.ensicaen.fr>

### Tutors

 - **Baptiste HEMERY** - <baptiste.hemery@ensicaen.fr>
 - **Estelle CHERRIER** - <estelle.cherrier@ensicaen.fr>

----------

## License

For AutoMix Software  
Copyright (c) 2016-2017, ENSICAEN All rights reserved.  
This project is licensed under Proprietary License - see the [LICENSE.md](LICENSE.md) file for details.