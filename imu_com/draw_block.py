import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.mplot3d.art3d import Poly3DCollection, Line3DCollection
from scipy.spatial.transform import Rotation

# Euler angles (in degrees)
roll = 30
pitch = 45
yaw = 60

# Define the dimensions of the block
length = 1
width = 2
height = 3

# Create the vertices of the block
vertices = np.array([
    [-length / 2, -width / 2, -height / 2],
    [length / 2, -width / 2, -height / 2],
    [length / 2, width / 2, -height / 2],
    [-length / 2, width / 2, -height / 2],
    [-length / 2, -width / 2, height / 2],
    [length / 2, -width / 2, height / 2],
    [length / 2, width / 2, height / 2],
    [-length / 2, width / 2, height / 2]
])

# Create the rotation matrix using Euler angles
rotation = Rotation.from_euler('xyz', [roll, pitch, yaw], degrees=True)
rotation_matrix = rotation.as_matrix()

# Rotate the vertices
rotated_vertices = np.dot(vertices, rotation_matrix.T)

# Define the faces of the block
faces = np.array([
    [0, 1, 2, 3],  # Bottom face
    [4, 5, 6, 7],  # Top face
    [0, 1, 5, 4],  # Side face 1
    [1, 2, 6, 5],  # Side face 2
    [2, 3, 7, 6],  # Side face 3
    [3, 0, 4, 7]   # Side face 4
])

# Define the edges of the block
edges = np.array([
    [0, 1], [1, 2], [2, 3], [3, 0],  # Bottom face edges
    [4, 5], [5, 6], [6, 7], [7, 4],  # Top face edges
    [0, 4], [1, 5], [2, 6], [3, 7]   # Vertical edges
])

# Plot the 3D block
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot the faces of the block
ax.add_collection(Poly3DCollection([rotated_vertices[face] for face in faces], alpha=0.25))

# Plot the edges of the block with dark colors
ax.add_collection(Line3DCollection([rotated_vertices[edge] for edge in edges], colors='k'))

# Set the plot limits
ax.set_xlim([-length, length])
ax.set_ylim([-width, width])
ax.set_zlim([-height, height])

# Set the axes labels
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')

# Show the plot
plt.show()