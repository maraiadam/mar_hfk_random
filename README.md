# `mar_hfk_random` package
ROS 2 C++ package.  [![Static Badge](https://img.shields.io/badge/ROS_2-Humble-34aec5)](https://docs.ros.org/en/humble/)

Projekt leírás:
Ez a ROS 2 Humble package, amely egy távolságérzékelőt és egy ütközésjelző rendszert szimulál.
A csomag két node-ból áll:

distance_sensor_node – Szimulált távolságadatokat generál (sensor_msgs/Range).

collision_alert_node – Figyeli a távolságot, és ha az érték a beállított küszöb alá esik, ütközés figyelmeztetést küld (std_msgs/String).

## Packages and build

It is assumed that the workspace is `~/ros2_ws/`.

### Clone the packages
``` r
cd ~/ros2_ws/src
```
``` r
git clone https://github.com/maraiadam/mar_hfk_random
```

### Build ROS 2 packages
``` r
cd ~/ros2_ws
```
``` r
colcon build --packages-select mar_hfk_random --symlink-install
```

<details>
<summary> Don't forget to source before ROS commands.</summary>

``` bash
source ~/ros2_ws/install/setup.bash
```

</details>

``` r
ros2 launch mar_hfk_random collision_system.launch.py
```