import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.art3d import Poly3DCollection

def make_parallelepiped(center, size, direction, facecolor):
    # Compute half of the size in each direction
    half_size = np.array(size) / 2.0
    # Compute the basis vectors of the parallelepiped
    v1, v2, v3 = np.array(direction) * half_size[:, np.newaxis]
    # Compute the vertices of the parallelepiped
    vertices = [center + v1 + v2 + v3,
                center + v1 - v2 + v3,
                center - v1 - v2 + v3,
                center - v1 + v2 + v3,
                center + v1 + v2 - v3,
                center + v1 - v2 - v3,
                center - v1 - v2 - v3,
                center - v1 + v2 - v3]
    # Define the faces of the parallelepiped
    faces = [[0, 1, 2, 3], [4, 5, 6, 7], [0, 1, 5, 4],
             [1, 2, 6, 5], [2, 3, 7, 6], [0, 3, 7, 4]]
    # Create a Poly3DCollection object for the parallelepiped
    parallelepiped = Poly3DCollection([[vertices[i] for i in face] for face in faces], alpha=.25, facecolor=facecolor)
    return parallelepiped

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Define the first parallelepiped
center1 = np.array([50, 50, 50])
size1 = np.array([50, 30, 100])
direction = [1, 1, 1]
direction1 = np.diag(direction)
parallelepiped1 = make_parallelepiped(center1, size1, direction1, "r")
ax.add_collection3d(parallelepiped1)

# Define the second parallelepiped
center2 = np.array([40, 100, 25])
size2 = np.array([70, 60, 50])
direction2 = [1, 0.5, 1]
direction2 = np.diag(direction2)
parallelepiped2 = make_parallelepiped(center2, size2, direction2, "b")
ax.add_collection3d(parallelepiped2)


# Set the limits of the plot
ax.set_xlim([0, 80])
ax.set_ylim([0, 120])
ax.set_zlim([0, 230])

# Set labels for the axes
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')

# Set the aspect ratio of the plot
ax.set_box_aspect([80,120,230])

# Show the plot
plt.show()