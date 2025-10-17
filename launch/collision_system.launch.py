from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='mar_hfk_random',
            executable='distance_sensor_node',
            name='distance_sensor'
        ),
        Node(
            package='mar_hfk_random',
            executable='collision_alert_node',
            name='collision_alert'
        )
    ])