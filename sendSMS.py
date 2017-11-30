import serial
from twilio.rest import Client

ser = serial.Serial('/dev/cu.usbmodem1421', 9600)

# Account ID
account_sid = "AC2c499a37e76bd87fb370afc8d6e57be7"

# Your Auth Token from twilio.com/console
auth_token  = ####################################

client = Client(account_sid, auth_token)

def sendText(reciever):
	message = client.messages.create(
		to=reciever,
		from_="+12019480413",
		body="Someone is at the front door for you!")


while True:
	console = ser.readline()
	if console[0] == "+":
		sendText(console)
