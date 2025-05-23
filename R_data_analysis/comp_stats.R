get_sqrt <- function(a, tol = 1e-8, iter_max = 1000, verbose = FALSE) {
  # A short description of the function: Computes the square root of a non-negative number using Newton's method
  # Args:
  # a: Non-negative number to compute the square root of (numeric)
  # tol: Tolerance for stopping criterion (numeric, default is 1e-8)
  # iter_max: Maximum number of iterations allowed (integer, default is 1000)
  # verbose: Determines if you want to display intermediate results (logical, default is FALSE)
  # Return:
  # sqrt_a: Square root of the non-negative number (numeric)
  
  if (a < 0) {
    stop("The input number should be non-negative.")
  }
  
  x0 <- a / 2
  iter <- 0
  
  while (iter < iter_max) {
    x1 <- x0 - (x0^2 - a) / (2 * x0)
    
    if (verbose) {
      cat("Iteration:", iter + 1, "Current estimate:", x1, "\n")
    }
    
    if (abs(x1 - x0) < tol) {
      break
    }
    
    x0 <- x1
    iter <- iter + 1
  }
  
  sqrt_a <- x1
  return(sqrt_a)
}

get_abroot <- function(a, root, tol = 1e-8, iter_max = 1000, verbose = FALSE) {
  # A short description of the function: Calculates the arbitrary root of a non-negative number using Newton's method
  # Args:
  # a: Non-negative number to compute the arbitrary root of (numeric)
  # root: The root argument (numeric)
  # tol: Tolerance for stopping criterion (numeric, default is 1e-8)
  # iter_max: Maximum number of iterations allowed (integer, default is 1000)
  # verbose: Determines if you want to display intermediate results (logical, default is FALSE)
  # Return:
  # abroot_a: Arbitrary root of the non-negative number (numeric)
  
  if (a < 0) {
    stop("The input number should be non-negative.")
  }
  
  x0 <- a / 2
  iter <- 0
  
  while (iter < iter_max) {
    x1 <- x0 - (x0^root - a) / (root * x0^(root - 1))
    
    if (verbose) {
      cat("Iteration:", iter + 1, "Current estimate:", x1, "\n")
    }
    
    if (abs(x1 - x0) < tol) {
      break
    }
    
    x0 <- x1
    iter <- iter + 1
  }
  
  abroot_a <- x1
  return(abroot_a)
}

get_abroot_with_errors <- function(a, root, tol = 1e-8, iter_max = 1000, verbose = FALSE) {
  # A short description of the function: Calculates the arbitrary root of a non-negative number using Newton's method
  # Args:
  # a: Non-negative number to compute the arbitrary root of (numeric)
  # root: The root argument (numeric)
  # tol: Tolerance for stopping criterion (numeric, default is 1e-8)
  # iter_max: Maximum number of iterations allowed (integer, default is 1000)
  # verbose: Determines if you want to display intermediate results (logical, default is FALSE)
  # Return:
  # List of size 2:
  #   abroot_a: The arbitrary root of the non-negative number (numeric)
  #   errors: The errors of the first four iterations (numeric)
  if (a < 0) {
    stop("The input number should be non-negative.")
  }
  
  x0 <- a / 2
  iter <- 0
  errors <- numeric(iter_max) # Initialize an empty numeric vector to store the errors
  
  while (iter < iter_max) {
    x1 <- x0 - (x0^root - a) / (root * x0^(root - 1))
    
    error <- abs(x1 - a^(1/root))
    errors[iter + 1] <- error # Store the error at the current iteration
    
    if (verbose) {
      cat("Iteration:", iter + 1, "Current estimate:", x1, "Error:", error, "\n")
    }
    
    if (abs(x1 - x0) < tol) {
      break
    }
    
    x0 <- x1
    iter <- iter + 1
  }
  
  abroot_a <- x1
  errors <- errors[1:(iter + 1)] # Truncate the errors vector to keep only the relevant errors
  list(root = abroot_a, errors = errors)
}

get_min <- function(f, x0, n, alpha, tol = 1e-8, iter_max = 1000) {
  # Args:
  # f: An expression representing the function to minimize
  # x0: Numeric, the initial guess for the minimum
  # n: Integer, the power in the function
  # alpha: Numeric, a positive constant in the function
  # tol: Numeric, the tolerance for convergence (default: 1e-8)
  # iter_max: Integer, the maximum number of iterations (default: 1000)
  # Return:
  # Numeric, the minimum of the function f
  f_prime <- D(f, "x")
  f_double_prime <- D(f_prime, "x")
  
  iter <- 0
  x <- x0
  
  while (iter < iter_max) {
    x1 <- x - eval(f_prime) / eval(f_double_prime)
    
    if (abs(x1 - x) < tol) {
      break
    }
    
    x <- x1
    iter <- iter + 1
  }
  
  x1
}

# Modified get_min function to return the steps taken
get_min_with_steps <- function(f, x0, n, alpha, tol = 1e-8, iter_max = 1000) {
  # This function finds the minimum of a given function f using Newton's method and returns the steps taken.
  # Args:
  # f: An expression representing the function to minimize
  # x0: Numeric, the initial guess for the minimum
  # n: Integer, the power in the function
  # alpha: Numeric, a positive constant in the function
  # tol: Numeric, the tolerance for convergence (default: 1e-8)
  # iter_max: Integer, the maximum number of iterations (default: 1000)
  # Return:
  # List of size 2:
  #   minimum: Numeric, the minimum of the function f
  #   steps: Numeric vector, the sequence of x values for each step taken by Newton's method
  f_prime_expr <- D(f, "x")
  f_double_prime_expr <- D(f_prime_expr, "x")
  
  f_prime <- function(x, n, alpha) {
    eval(f_prime_expr)
  }
  
  f_double_prime <- function(x, n, alpha) {
    eval(f_double_prime_expr)
  }
  
  iter <- 0
  x <- x0
  steps <- c(x)
  
  while (iter < iter_max) {
    f_prime_val <- f_prime(x, n, alpha)
    f_double_prime_val <- f_double_prime(x, n, alpha)
    
    x1 <- x - f_prime_val / f_double_prime_val
    steps <- c(steps, x1)
    
    if (abs(x1 - x) < tol) {
      break
    }
    
    x <- x1
    iter <- iter + 1
  }
  
  list(minimum = x1, steps = steps)
}