"""
Program Name: Essay Class
Filename:     main.py
Author:       Brandon Montez
Date:         2020-12-1
Assignment:   13
Description:  Provides the grade for a student's essay
Sources:      None.
"""

class GradedActivity: #Class GradedActivity
	# The score field holds a numeric score.
	#Private Real score
	
	# Mutator
	def setScore(self, s): #Public Module setScore(Real s)
		self._score = s #Set score = s
	#End Module
	
	# Accessor
	def getScore(self): #Public Function Real getScore()
		return self._score #Return score
	#End Function
	
	# getGrade method
	def getGrade(self): #Public Function String getGrade()
		# Local variable to hold a grade.
		grade = "" #Declare String grade
		
		# Determine the grade.
		if self._score >= 90: #If score >= 90 Then
			grade = "A" #Set grade = "A"
		elif self._score >= 80: #Else If score >= 80 Then
			grade = "B" #Set grade = "B"
		elif self._score >= 70: #Else If score >= 70 Then
			grade = "C" #Set grade = "C"
		elif self._score >= 60: #Else If score >= 60 Then
			grade = "D" #Set grade = "D"
		else: #Else
			grade = "F" #Set grade = "F"
		#End If 

		# Return the grade.
		return grade #Return grade
	#End Function
#End Class 

class Essay(GradedActivity):
  """
  Class Name:   Essay
  Description:  Grading rubric for essay scores
  """

  def __init__(self, g, s, l, c):
    """
    Module Name:  __init__
    Parameters:   Essay -> self: this instance of the Essay class
                  Int -> g: grammar points
                  Int -> s: spelling points
                  Int -> l: length points
                  Int -> c: content points
    Description:  Constructor for an essay evaluator
    """
    # Calculate total points
    self._points = g + s + l + c

    # Set score to total points
    self.setScore(self._points)
    
  # Accessor
  def get_points(self):
    """
    Module Name:  get_points
    Parameters:   Essay -> self: this instance of the Essay class
    Description:  Returns the essay's point total
    """
    return self._points

  # Accessor
  def get_grade(self):
    """
    Module Name:  get_grade
    Parameters:   Essay -> self: this instance of the Essay class
    Description:  Returns the essay's grade. 
    """
    return self.getGrade()

def main():
  """
  Module Name:  main
  Parameters:   None.
  Description:  Program starting point
  """
  # Collect scores for each category
  grammar = int(input("Please enter the student's points for grammar (up to 30 points): "))
  spelling = int(input("Please enter the student's points for spelling (up to 20 points): "))
  length = int(input("Please enter the student's points for correct length (up to 20 points): "))
  content = int(input("Please enter the student's points for content (up to 30 points): "))

  # Create a new essay object
  essay = Essay(grammar, spelling, length, content)

  # Evaluate essay
  points = essay.get_points()
  grade = essay.get_grade()

  # Display results
  print()
  print("Student's overall points are:", points)
  print("Student's overall grade is:", grade)

if __name__ == "__main__":
  main()

