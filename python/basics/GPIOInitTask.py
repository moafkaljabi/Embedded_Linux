def prompt_user_for_bit_modes(port_name):
    """
    Prompts the user to enter the mode (input/output) for each bit of the specified port.
    
    Parameters:
    port_name (str): The name of the port (e.g., 'PORTB').

    Returns:
    list: A list containing the mode ('input' or 'output') for each bit (0 to 7).
    """
    modes = []
    for bit in range(8):
        while True:
            mode = input(f"Please enter bit {bit} mode for {port_name} (input/output): ").strip().lower()
            if mode in ['input', 'output']:
                modes.append(mode)
                break
            else:
                print("Invalid input. Please enter 'input' or 'output'.")
    return modes

def generate_gpio_init(port_name, modes):
    """
    Generates the GPIO initialization function for AVR.

    Parameters:
    port_name (str): The name of the port (e.g., 'PORTB').
    modes (list): List of modes ('input' or 'output') for each bit (0 to 7).

    Returns:
    str: The generated C code for GPIO initialization.
    """
    ddr = f"DDR{port_name[-1]}"
    port_reg = f"PORT{port_name[-1]}"
    function_code = f"void GPIO_Init(void) {{\n"
    function_code += f"    {ddr} = 0x00; // Set all pins as input by default\n"
    function_code += f"    {port_reg} = 0x00; // Set all pins to low by default\n"

    for bit, mode in enumerate(modes):
        if mode == 'output':
            function_code += f"    {ddr} |= (1 << {bit}); // Set {port_name[4]}{bit} as output\n"
        else:  # mode == 'input'
            function_code += f"    {port_reg} |= (1 << {bit}); // Enable pull-up resistor for {port_name[4]}{bit}\n"

    function_code += "}\n"
    return function_code

# Main script
port_name = 'PORTB'  # Example port
modes = prompt_user_for_bit_modes(port_name)
init_function_code = generate_gpio_init(port_name, modes)
print(init_function_code)
