from twilio.rest import Client

# Account ID
account_sid = "AC2c499a37e76bd87fb370afc8d6e57be7"
# Your Auth Token from twilio.com/console
auth_token  = "#################################"

client = Client(account_sid, auth_token)

message = client.messages.create(
	to="+17323433511", 
	from_="+12019480413",
	body="Python Script Test")

print(message.sid)
