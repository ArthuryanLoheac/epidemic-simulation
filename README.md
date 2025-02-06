# 🌍 Epidemic Simulation

_Epidemic Simulation_ is a C++ project designed to model the spread of a disease within a population. This simulation allows you to observe the impact of various parameters such as transmission rate, disease duration, and recovery and mortality rates.

## 🔧 Features
- 📊 Visual simulation of an epidemic spread.
- ⚖️ Customizable parameters to adjust disease dynamics.
- 🔢 Real-time display of epidemic statistics.
- ⏩ Controls to adjust simulation speed and restart the simulation.

## 📝 Prerequisites
- **C++ Compiler** (g++, clang, etc.).
- **Make** for build management.
- **SFML Library** for graphical rendering.

## 🔺 Installation
1. Clone the project repository:
   ```bash
   git clone git@github.com:ArthuryanLoheac/epidemic-simulation.git
   cd MaladieSimulation
   ```
2. Compile the project with the command:
   ```bash
   make
   ```
3. Run the simulation:
   ```bash
   ./simulation
   ```
   Or directly:
   ```bash
   make run
   ```

## 🔄 Controls
- **R** : Restart the simulation.
- **Arrow Up/Down** : Increase or decrease the simulation speed.

## 📊 Simulation Parameters

These parameters can be modified in the configuration file or directly in the source code.

- **RADIUS_CIRCLE** : Radius representing each individual. **(Default: 5)**
- **NB_HOUSE** : Number of houses in the simulation. **(Default: 30)**
- **HOUSE_SIZE** : Size of each house. **(Default: 20)**
- **NB_WORK_POINT** : Number of points of interest (workplaces, etc.). **(Default: 20)**
- **MIN_SECONDS_WORKING / MAX_SECONDS_WORKING** : Minimum/maximum time spent at points of interest. **(Default: 2 / 1 seconds)**
- **NB_PLACE_VISIT_A_DAY** : Number of places visited per day. **(Default: 1)**
- **NUMBER_PERSON** : Total number of individuals in the simulation. **(Default: 200)**
- **NUMBER_INFECTED_START** : Number of infected individuals at the start of the simulation. **(Default: 2)**
- **TIME_SICK** : Duration of the disease (in days). **(Default: 3 days)**
- **PERCENT_DEAD** : Mortality rate at the end of the disease. **(Default: 10%)**
- **PERCENT_RECOVERED** : Recovery rate at the end of the disease. **(Default: 95%)**
- **PERCENT_TRANSMISSION_WORK** : Probability of disease transmission at a workplace (per second). **(Default: 5%)**
- **PERCENT_TRANSMISSION_HOME** : Probability of disease transmission at home (per second). **(Default: 10%)**
- **LIFE_TIME** : Average lifespan of individuals (in days). **(Default: 10 days)**
- **PERCENT_IMUNE_BORN** : Percentage of individuals born immune. **(Default: 5%)**

## 🎟️ Demo
### Screenshot
![Screenshot](https://github.com/user-attachments/assets/acccbec0-722a-463e-8d30-7e25bc1fb404)

### Video
https://github.com/user-attachments/assets/fd61e0ba-5bcf-48ee-bcce-7fc31ac2b4af

## 🌟 Contributions
Contributions are welcome! Please submit pull requests to suggest improvements or fix bugs.

---

For any questions or suggestions, feel free to open an issue on the GitHub repository. 🚀




