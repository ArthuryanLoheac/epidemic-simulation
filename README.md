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
   git clone <repository-url>
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

- **WIN_WIDTH / WIN_HEIGHT** : Window width and height in pixels.
- **RADIUS_CIRCLE** : Radius representing each individual.
- **NB_HOUSE** : Number of houses in the simulation.
- **NB_WORK_POINT** : Number of points of interest (workplaces, etc.).
- **MIN_SECONDS_WORKING / MAX_SECONDS_WORKING** : Minimum/maximum time spent at points of interest.
- **NB_PLACE_VISIT_A_DAY** : Number of places visited per day.
- **NUMBER_PERSON** : Total number of individuals in the simulation.
- **SPEED_MIN / SPEED_MAX** : Minimum/maximum movement speed of individuals.
- **NUMBER_INFECTED_START** : Number of infected individuals at the start of the simulation.
- **TIME_SICK** : Duration of the disease (in days).
- **PERCENT_DEAD** : Mortality rate at the end of the disease.
- **PERCENT_RECOVERED** : Recovery rate at the end of the disease.
- **PERCENT_TRANSMISSION_WORK** : Probability of disease transmission at a workplace (per second).
- **PERCENT_TRANSMISSION_HOME** : Probability of disease transmission at home (per second).

## 🎟️ Demo
### Screenshot


### Video


## 🌟 Contributions
Contributions are welcome! Please submit pull requests to suggest improvements or fix bugs.

---

For any questions or suggestions, feel free to open an issue on the GitHub repository. 🚀

