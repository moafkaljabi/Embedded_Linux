import tkinter as tk
from tkinter import scrolledtext, messagebox
import threading
import speech_recognition as sr
import pyttsx3
import pywhatkit
import datetime
import wikipedia
import pyjokes
import webbrowser
import playsound
from gtts import gTTS


class VoiceAssistantApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Voice Assistant")
        self.root.geometry("600x500")
        self.root.config(bg="#f0f0f0")

        self.setup_ui()

        # Initialize the speech recognizer and TTS engine
        self.listener = sr.Recognizer()
        self.engine = pyttsx3.init()
        voices = self.engine.getProperty('voices')
        self.engine.setProperty('voice', voices[1].id)

        # Flag to track if assistant is currently listening
        self.is_listening = False

    def setup_ui(self):
        title_label = tk.Label(self.root, text="Voice Assistant", font=("Helvetica", 24), bg="#007BFF", fg="white", padx=10, pady=10)
        title_label.pack(fill=tk.X)

        self.text_area = scrolledtext.ScrolledText(self.root, wrap=tk.WORD, width=60, height=15, font=("Arial", 12))
        self.text_area.pack(pady=20)

        # Start/Stop Assistant button
        self.start_button = tk.Button(self.root, text="Start Assistant", font=("Arial", 14), bg="#4CAF50", fg="white", padx=20, pady=10, command=self.start_assistant)
        self.start_button.pack()

    def talk(self, text):
        # Use gTTS instead of pyttsx3
        tts = gTTS(text=text, lang='en')
        tts.save("response.mp3")
        playsound.playsound("response.mp3")

    def take_command(self):
        command = ""  # Initialize command with an empty string
        try:
            with sr.Microphone() as source:
                print('listening...')
                voice = self.listener.listen(source)
                command = self.listener.recognize_google(voice)
                command = command.lower()
                if 'alexa' in command:
                    command = command.replace('alexa', '')
                    print(command)
        except:
            pass
        return command

    def run_alexa(self):
        command = self.take_command()
        self.display_command(command)
        print(command)
        if 'play' in command:
            song = command.replace('play', '')
            self.talk('playing ' + song)
            pywhatkit.playonyt(song)
        elif 'time' in command:
            time_now = datetime.datetime.now().strftime('%I:%M %p')
            self.talk('Current time is ' + time_now)
        elif 'who the heck is' in command:
            person = command.replace('who the heck is', '')
            info = wikipedia.summary(person, 1)
            print(info)
            self.talk(info)
        elif 'date' in command:
            self.talk('sorry, I have a headache')
        elif 'are you single' in command:
            self.talk('I am in a relationship with wifi')
        elif 'joke' in command:
            self.talk(pyjokes.get_joke())
        elif 'open' in command:
            website = command.replace('open', '')
            self.talk('Opening ' + website)
            webbrowser.open('http://' + website)
        else:
            self.talk('Please say the command again.')

    def start_listening(self):
        while self.is_listening:
            self.run_alexa()

    def start_assistant(self):
        if not self.is_listening:
            self.is_listening = True
            self.start_button.config(text="Stop Listening", bg="#FF5733")
            thread = threading.Thread(target=self.start_listening)
            thread.start()
        else:
            self.is_listening = False
            self.start_button.config(text="Start Assistant", bg="#4CAF50")

    def display_command(self, command):
        self.text_area.insert(tk.END, f"Command: {command}\n")
        self.text_area.see(tk.END)


if __name__ == "__main__":
    root = tk.Tk()
    app = VoiceAssistantApp(root)
    root.mainloop()
