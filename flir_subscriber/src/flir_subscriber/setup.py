from setuptools import setup

package_name = 'flir_subscriber'

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
    maintainer='samuel',
    maintainer_email='samuel@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'flir_subscriber = flir_subscriber.flir_subscriber_fps_test:main',
            'flir_subscriber_echo = flir_subscriber.flir_subscriber_2:main',
        ],
    },
)
