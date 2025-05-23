import numpy as np

# Given matrix A.
A = np.array([[1, 0], [2, 7], [3, 5]])

# Compute A^T A and A A^T.
AtA = np.dot(A.T, A)
AAt = np.dot(A, A.T)

# Find eigenvalues and eigenvectors of A^T A for V.
eigenvalues_v, eigenvectors_v = np.linalg.eig(AtA)

# Find eigenvalues and eigenvectors of A A^T for U.
eigenvalues_u, eigenvectors_u = np.linalg.eig(AAt)

# Sort eigenvalues and eigenvectors for V in descending order.
sort_indices_v = np.argsort(eigenvalues_v)[::-1]
eigenvalues_v = eigenvalues_v[sort_indices_v]
eigenvectors_v = eigenvectors_v[:, sort_indices_v]

# Sort eigenvalues and eigenvectors for U in descending order.
sort_indices_u = np.argsort(eigenvalues_u)[::-1]
eigenvalues_u = eigenvalues_u[sort_indices_u]
eigenvectors_u = eigenvectors_u[:, sort_indices_u]

# Compute the singular values as the non-zero eigenvalues' square roots from either matrix.
singular_values = np.sqrt(eigenvalues_v)

# Set U and V matrices.
U = eigenvectors_u
V = eigenvectors_v

# Take the first two columns of U and V, and the two largest singular values.
U_rank2 = U[:, :2]
V_rank2 = V[:, :2]
singular_values_rank2 = singular_values[:2]

# Display
print("U (thin rank-2) =\n", U_rank2)
print("Singular values (rank-2) =\n", singular_values_rank2)
print("V^T (rank-2) =\n", V_rank2.T)