from plyer import notification
import psutil


battery = psutil.sensors_battery()
percent = battery.percent
print(percent)


notification.notify(title = "Power alert", message = f"{percent} remaining", timeout =10)


# Notification("Batery percentage is ", str(percent)+ "% Percent remaining",duration = 10).send()
