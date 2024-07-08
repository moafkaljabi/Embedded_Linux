
# 1. import math library
# 2. define a function to check:
#       if value is negative and valid 

# 3. define function to calculate
# 4. define main function
# 5. Ensure the script can be run directly





import math

def get_radius():
    while True:
        try:
            radius = float(input("Enter a radius value:"))
            if radius < 0:
                print("radius can not be negative.")
            else:
                return radius
        except ValueError:
            print("Invalid input, please enter a neumerical value")
        
def calculate_area(radius):
    return math.pi *(radius ** 2)


def main():
    radius = get_radius()
    area = calculate_area(radius)
    print(f"Area of the circle for the entered radius {radius} is: {area:.3f}")


if __name__ == "__main__":
    main()