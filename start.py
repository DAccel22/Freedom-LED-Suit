import time #Time package gives time syncing functionality
from digi.xbee.devices import XBeeDevice #XBee package gives XBee management functionality
import pygame #Pygame package gives music playing functionality
from pygame import mixer 

port = "COM7" #The port the XBee is plugged in to.
BR = 9600 #Baud rate, configured in XCTU. Should stay as 9600.
my_xbee = XBeeDevice(port, BR) #Declare/name the XBee that is plugged into the computer as "my_xbee"

song = "Freedom.mp3" #This is the file name of the song you're using. Make sure this song file lives in the same folder as the code.
mixer.init()	
mixer.music.load(song) #Load the song

#Initialize light timing things, add as many cues as needed.
cueA = False
cueB = False
cueC = False
cueD = False
cueE = False
cueF = False
cueG = False
cueH = False
cueZ = False


mixer.music.play() #Start playing the song

while pygame.mixer.music.get_busy(): #While the music is playing,
	ts = pygame.mixer.music.get_pos()/1000.0 #Get the timestamp in the music
	if (ts>0 and cueZ == False): #If it's when we want to trigger cue A, in this case at 6.7 seconds, and we haven't sent cue A yet
		my_xbee.open() #Open XBee for transmission
		my_xbee.send_data_broadcast('Z') #Send the letter A
		my_xbee.send_data_broadcast('Z')
		my_xbee.send_data_broadcast('Z')
		my_xbee.close()	#Close the XBee
		cueZ = True	#Switch the logic gate to True
		print("cueZ = True") #Print statements to keep track
		print("Z sent")
	if (ts>2.823529412 and cueA == False): #If it's when we want to trigger cue A, in this case at 6.7 seconds, and we haven't sent cue A yet
		my_xbee.open() #Open XBee for transmission
		my_xbee.send_data_broadcast('A') #Send the letter A
		my_xbee.send_data_broadcast('I')
		my_xbee.send_data_broadcast('R')
		my_xbee.close()	#Close the XBee
		cueA = True	#Switch the logic gate to True
		print("cueA = True") #Print statements to keep track
		print("A sent")
	
	if (ts>28.23529412 and cueB == False):
		my_xbee.open()
		my_xbee.send_data_broadcast('B')
		my_xbee.send_data_broadcast('J')
		my_xbee.send_data_broadcast('S')
		my_xbee.close()	
		cueB = True	
		print("cueB = True")
		print("B sent")		

	if (ts>50.82352941 and cueC == False):
		my_xbee.open()
		my_xbee.send_data_broadcast('C')
		my_xbee.send_data_broadcast('K')
		my_xbee.send_data_broadcast('T')
		my_xbee.close()	
		cueC = True	
		print("cueC = True")
		print("C sent")			

	if (ts>62.11764706 and cueD == False):
		my_xbee.open()
		my_xbee.send_data_broadcast('D')
		my_xbee.send_data_broadcast('L')
		my_xbee.send_data_broadcast('U')
		my_xbee.close()	
		cueD = True	
		print("cueD = True")
		print("D sent")	

	if (ts>84.70588235 and cueE == False):
		my_xbee.open()
		my_xbee.send_data_broadcast('E')
		my_xbee.send_data_broadcast('N')
		my_xbee.send_data_broadcast('V')
		my_xbee.close()	
		cueE = True	
		print("cueE = True")
		print("E sent")

	if(ts>96 and cueF==False):
		my_xbee.open()
		my_xbee.send_data_broadcast('F')
		my_xbee.send_data_broadcast('O')
		my_xbee.send_data_broadcast('W')
		my_xbee.close()
		cueF=True
		print("cueF = True")
		print("F sent")

	if(ts>118.5882353 and cueG==False):
		my_xbee.open()
		my_xbee.send_data_broadcast('G')
		my_xbee.send_data_broadcast('P')
		my_xbee.send_data_broadcast('X')
		my_xbee.close()
		cueG=True
		print("cueF = True")
		print("G sent")

	if(ts>129.8823529 and cueH==False):
		my_xbee.open()
		my_xbee.send_data_broadcast('H')
		my_xbee.send_data_broadcast('Q')
		my_xbee.send_data_broadcast('Y')
		my_xbee.close()
		cueH=True
		print("cueH = True")
		print("H sent")

