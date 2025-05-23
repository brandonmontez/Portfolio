# Load the Legos data
legos <- read.table("Legos.txt", header = TRUE)

# Fit the linear model
lm1 <- lm(price ~ bricks, data = legos)

# Perform ANOVA on the model
anova(lm1)



# Residuals vs Fitted Plot
plot(lm1, which = 1)

# Normal QQ Plot
plot(lm1, which = 2)

# Residuals vs Leverage Plot
plot(lm1, which = 5)


legos$logbricks <- log(legos$bricks)
legos$logprice <- log(legos$price)



# Fit the linear model with log transformation
lm2 <- lm(logprice ~ logbricks, data = legos)

# Residuals vs Fitted Plot
plot(lm2, which = 1)

# Normal QQ Plot
plot(lm2, which = 2)

# Residuals vs Leverage Plot
plot(lm2, which = 5)





# Weighted
lm3 <- lm(price ~ bricks, data = legos, weight = 1 / bricks)

plot(lm3, which = 1)
plot(legos$bricks, resid(lm3), main = "Weighted Residuals")



library(readr)
armspans <- read_csv("armspans2022_gender.csv")

lm4 <- lm(armspan ~ is.female, data = armspans)

summary(lm4)

plot(lm4)
