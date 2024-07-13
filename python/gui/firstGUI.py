import tkinter as tk

# Create the main window
root = tk.Tk()

# Set the title of the window
root.title("Simple Tkinter Window")

# Set the size of the window
root.geometry("400x300")

# Create a label widget
label = tk.Label(root, text="Hello, Tkinter!")
label.pack(pady=20)

# Start the Tkinter event loop
root.mainloop()
