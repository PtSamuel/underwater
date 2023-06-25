from setuptools import setup

package_name = 'joy_subscriber'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='johnsmith',
    maintainer_email='johnsmith@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "joy_subscriber_node = joy_subscriber.joy_subscriber_node:main",
            "motor_controller_node = joy_subscriber.motor_controller_node:main",
        ],
    },
)
