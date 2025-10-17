from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='collision_alert_pkg',
            executable='distance_sensor_node',
            name='distance_sensor'
        ),
        Node(
            package='collision_alert_pkg',
            executable='collision_alert_node',
            name='collision_alert'
        )
    ])