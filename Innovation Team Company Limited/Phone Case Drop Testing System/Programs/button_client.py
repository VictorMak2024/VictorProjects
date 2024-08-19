#!/usr/bin/env python
import rospy
from std_srvs.srv import Trigger
import RPi.GPIO as GPIO
import sys
import time


pin_btnA = 5
pin_btnB = 16
pin_btnC = 23
pin_btnD = 6
pin_btnH = 21
pin_btnL = 20
pin_btnPower = 26
pin_btnOperator = 4
pin_btnRelease = 19
pin_relay=12


def button_A_callback(channel): # complete A button
    time.sleep(0.2)
    b_button = GPIO.input(pin_btnA)
    if(b_button == True):
        mode = rospy.get_param('/drop_mobile/mode')
        if(mode == "AutoRun"):
            pass
        elif(mode == "Customer"):
            stage = rospy.get_param('/drop_mobile/stage')
            if(stage == "Customer_9" ):
                try:
                    move = rospy.ServiceProxy('/drop_mobile/move_normal_btn_A', Trigger)
                    resp1 = move()
                    rospy.loginfo('Executing state AutoRun move_normal_btn_A')
                except rospy.ServiceException as e:
                    print("Service call failed: %s"%e)
            elif(stage == "Customer_12" ):
                try:
                    isBtnPress = rospy.get_param('/drop_mobile/isRestEnd')
                    if(isBtnPress == False):
                        rospy.set_param('/drop_mobile/isRestEnd', True)
                except rospy.ServiceException as e:
                    print("Service call failed: %s"%e)
        elif(mode == "Operator"):
            startTime = time.time()
            currentTime = time.time()
            while True:
                currentTime = time.time()
                b_button_A = GPIO.input(pin_btnA)
                b_button_B = GPIO.input(pin_btnB)
                if(b_button_A == True and b_button_B == True):
                    if((currentTime - startTime) >= 5):
                        isPress = rospy.get_param('/drop_mobile/isAandBPress')
                        if(isPress == False):
                            rospy.set_param('/drop_mobile/isAandBPress', True)
                        break
                else:
                    break
    while(b_button == True):
        b_button = GPIO.input(pin_btnA)
        if(b_button == False):
            break



def button_B_callback(channel):     # complete B button
    time.sleep(0.2)
    b_button2 = GPIO.input(pin_btnB)
    if(b_button2 == True):
        mode = rospy.get_param('/drop_mobile/mode')
        if(mode == "AutoRun"):
            pass
        elif(mode == "Customer"):
            stage = rospy.get_param('/drop_mobile/stage')
            if(stage == "Customer_9" ):
                try:
                    move = rospy.ServiceProxy('/drop_mobile/move_normal_btn_B', Trigger)
                    resp1 = move()
                    rospy.loginfo('Executing state AutoRun move_normal_btn_B')
                except rospy.ServiceException as e:
                    print("Service call failed: %s"%e)
            elif(stage == "Customer_12" ):
                try:
                    isBtnPress = rospy.get_param('/drop_mobile/isRestEnd')
                    if(isBtnPress == False):
                        rospy.set_param('/drop_mobile/isRestEnd', True)
                except rospy.ServiceException as e:
                    print("Service call failed: %s"%e)
        elif(mode == "Operator"):
            startTime = time.time()
            currentTime = time.time()
            while True:
                currentTime = time.time()
                b_button_A = GPIO.input(pin_btnA)
                b_button_B = GPIO.input(pin_btnB)
                if(b_button_A == True and b_button_B == True):
                    if((currentTime - startTime) >= 5):
                        isPress = rospy.get_param('/drop_mobile/isAandBPress')
                        if(isPress == False):
                            rospy.set_param('/drop_mobile/isAandBPress', True)
                        break
                else:
                    break
    while(b_button2 == True):
        b_button2 = GPIO.input(pin_btnB)
        if(b_button2 == False):
            break

def button_C_callback(channel): # complete C button
    time.sleep(0.2)
    b_button3 = GPIO.input(pin_btnC)
    if(b_button3 == True):
        mode = rospy.get_param('/drop_mobile/mode')
        if(mode == "AutoRun"):
            pass
        elif(mode == "Customer"):
            stage = rospy.get_param('/drop_mobile/stage')
            if(stage == "Customer_9" ):
                try:
                    move = rospy.ServiceProxy('/drop_mobile/move_normal_btn_C', Trigger)
                    resp1 = move()
                    rospy.loginfo('Executing state AutoRun move_normal_btn_C')
                except rospy.ServiceException as e:
                    print("Service call failed: %s"%e)
            elif(stage == "Customer_12" ):
                try:
                    isBtnPress = rospy.get_param('/drop_mobile/isRestEnd')
                    if(isBtnPress == False):
                        rospy.set_param('/drop_mobile/isRestEnd', True)
                except rospy.ServiceException as e:
                    print("Service call failed: %s"%e)
        elif(mode == "Operator"):
            startTime = time.time()
            currentTime = time.time()
            while True:
                currentTime = time.time()
                b_button_C = GPIO.input(pin_btnC)
                b_button_D = GPIO.input(pin_btnD)
                if(b_button_C == True and b_button_D == True):
                    if((currentTime - startTime) >= 5):
                        isPress = rospy.get_param('/drop_mobile/isCandDPress')
                        if(isPress == False):
                            rospy.set_param('/drop_mobile/isCandDPress', True)
                        break
                else:
                    break
    while(b_button3 == True):
        b_button3 = GPIO.input(pin_btnC)
        if(b_button3 == False):
            break

def button_D_callback(channel):
    time.sleep(0.2)
    b_button4 = GPIO.input(pin_btnD)
    if(b_button4 == True):
        mode = rospy.get_param('/drop_mobile/mode')
        if(mode == "AutoRun"):
            pass
        elif(mode == "Customer"):
            stage = rospy.get_param('/drop_mobile/stage')
            if(stage == "Customer_9" ):
                try:
                    move = rospy.ServiceProxy('/drop_mobile/move_normal_btn_D', Trigger)
                    resp1 = move()
                    rospy.loginfo('Executing state AutoRun move_normal_btn_D')
                except rospy.ServiceException as e:
                    print("Service call failed: %s"%e)
            elif(stage == "Customer_12" ):
                try:
                    isBtnPress = rospy.get_param('/drop_mobile/isRestEnd')
                    if(isBtnPress == False):
                        rospy.set_param('/drop_mobile/isRestEnd', True)
                except rospy.ServiceException as e:
                    print("Service call failed: %s"%e)
        elif(mode == "Operator"):
            startTime = time.time()
            currentTime = time.time()
            while True:
                currentTime = time.time()
                b_button_C = GPIO.input(pin_btnC)
                b_button_D = GPIO.input(pin_btnD)
                if(b_button_C == True and b_button_D == True):
                    if((currentTime - startTime) >= 5):
                        isPress = rospy.get_param('/drop_mobile/isCandDPress')
                        if(isPress == False):
                            rospy.set_param('/drop_mobile/isCandDPress', True)
                        break
                else:
                    break
    while(b_button4 == True):
        b_button4 = GPIO.input(pin_btnD)
        if(b_button4 == False):
            break


def button_H_callback(channel):
    time.sleep(0.2)
    b_buttonH =GPIO.input(pin_btnH)
    if(b_buttonH == True):
        mode = rospy.get_param('/drop_mobile/mode')
        if(mode == "AutoRun"):
            pass
        elif(mode == "Customer"):
            stage = rospy.get_param('/drop_mobile/stage')
            if(stage == "Customer_9" ):
                try:
                    move = rospy.ServiceProxy('/drop_mobile/move_normal_btn_H', Trigger)
                    resp1 = move()
                    rospy.loginfo('Executing state AutoRun move_normal_btn_H')
                except rospy.ServiceException as e:
                    print("Service call failed: %s"%e)
            elif(stage == "Customer_12" ):
                try:
                    isBtnPress = rospy.get_param('/drop_mobile/isRestEnd')
                    if(isBtnPress == False):
                        rospy.set_param('/drop_mobile/isRestEnd', True)
                except rospy.ServiceException as e:
                    print("Service call failed: %s"%e)
        elif(mode == "Operator"):
            startTime = time.time()
            currentTime = time.time()
            while True:
                currentTime = time.time()
                b_button_H = GPIO.input(pin_btnH)
                b_button_L = GPIO.input(pin_btnL)
                if(b_button_H == True and b_button_L == True):
                    if((currentTime - startTime) >= 5):
                        isPress = rospy.get_param('/drop_mobile/isHandLPress')
                        if(isPress == False):
                            rospy.set_param('/drop_mobile/isHandLPress', True)
                        break
                else:
                    break
    while(b_buttonH == True):
        b_buttonH = GPIO.input(pin_btnH)
        if(b_buttonH == False):
            break


def button_L_callback(channel):
    time.sleep(0.2)
    b_buttonL = GPIO.input(pin_btnL)
    if(b_buttonL == True):
        mode = rospy.get_param('/drop_mobile/mode')
        if(mode == "AutoRun"):
            pass
        elif(mode == "Customer"):
            stage = rospy.get_param('/drop_mobile/stage')
            if(stage == "Customer_9" ):
                try:
                    move = rospy.ServiceProxy('/drop_mobile/move_normal_btn_L', Trigger)
                    resp1 = move()
                    rospy.loginfo('Executing state AutoRun move_normal_btn_L')
                except rospy.ServiceException as e:
                    print("Service call failed: %s"%e)
            elif(stage == "Customer_12" ):
                try:
                    isBtnPress = rospy.get_param('/drop_mobile/isRestEnd')
                    if(isBtnPress == False):
                        rospy.set_param('/drop_mobile/isRestEnd', True)
                except rospy.ServiceException as e:
                    print("Service call failed: %s"%e)
        elif(mode == "Operator"):
            startTime = time.time()
            currentTime = time.time()
            while True:
                currentTime = time.time()
                b_button_H = GPIO.input(pin_btnH)
                b_button_L = GPIO.input(pin_btnL)
                if(b_button_H == True and b_button_L == True):
                    if((currentTime - startTime) >= 5):
                        isPress = rospy.get_param('/drop_mobile/isHandLPress')
                        if(isPress == False):
                            rospy.set_param('/drop_mobile/isHandLPress', True)
                        break
                else:
                    break
    while(b_buttonL == True):
        b_buttonL = GPIO.input(pin_btnL)
        if(b_buttonL == False):
            break


def button_Power_callback(channel):
    while True:
	    time.sleep(1.5)
	    b_init = GPIO.input(pin_btnPower)
	    time.sleep(0.5)
	    b_button_Power = GPIO.input(pin_btnPower)
	    b_button_Operator = GPIO.input(pin_btnOperator)
	    if(b_init == b_button_Power):
		    if(b_button_Operator == True):
		        rospy.set_param('/drop_mobile/mode',"Operator")
		        mode = rospy.get_param('/drop_mobile/mode')
		        print("button_Power_callback    mode: "+ str(mode))
		    else:
		        b_button_Power = GPIO.input(pin_btnPower)
		        if(b_button_Power == True):
		            rospy.set_param('/drop_mobile/mode',"Customer")
		            mode = rospy.get_param('/drop_mobile/mode')
		            print("button_Power_callback    mode: "+ str(mode))
		        else:
		            rospy.set_param('/drop_mobile/mode',"AutoRun")
		            mode = rospy.get_param('/drop_mobile/mode')
		            print("button_Power_callback    mode: "+ str(mode))
		    break
	    else:
	        print("Error button_Power_callback")
	        print(b_init)
	        print(b_button_Power)



def button_Operator_callback(channel):
    while True:
	    time.sleep(1.5)
	    b_init = GPIO.input(pin_btnOperator)
	    time.sleep(0.5)
	    b_button_Operator = GPIO.input(pin_btnOperator)
	    if(b_init == b_button_Operator):
		    if(b_button_Operator == True):
		        rospy.set_param('/drop_mobile/mode',"Operator")
		        mode = rospy.get_param('/drop_mobile/mode')
		        print("button_Operator_callback    mode: "+ str(mode))
		    else:
		        b_button_Power = GPIO.input(pin_btnPower)
		        if(b_button_Power == True):
		            rospy.set_param('/drop_mobile/mode',"Customer")
		            mode = rospy.get_param('/drop_mobile/mode')
		            print("button_Operator_callback    mode: "+ str(mode))
		        else:
		            rospy.set_param('/drop_mobile/mode',"AutoRun")
		            mode = rospy.get_param('/drop_mobile/mode')
		            print("button_Operator_callback    mode: "+ str(mode))
		    break
	    else:
	        print("Error button_Operator_callback")
	        print(b_init)
	        print(b_button_Operator)

def gripper_release_callback(channel):
    time.sleep(0.2)
    b_button_gripper = GPIO.input(pin_btnRelease)
    if(b_button_gripper == True):
        mode = rospy.get_param('/drop_mobile/mode')
        if(mode == "AutoRun"):
            pass
        elif(mode == "Customer"):
            stage = rospy.get_param('/drop_mobile/stage')
            if(stage == "Customer_9" ):
                isPress = rospy.get_param('/drop_mobile/isPressRelease')
                if(isPress == False):
                    rospy.set_param('/drop_mobile/isPressRelease', True)
            elif(stage == "Customer_12" ):
                try:
                    isBtnPress = rospy.get_param('/drop_mobile/isRestEnd')
                    if(isBtnPress == False):
                        rospy.set_param('/drop_mobile/isRestEnd', True)
                except rospy.ServiceException as e:
                    print("Service call failed: %s"%e)
        elif(mode == "Operator"):
            startTime = time.time()
            currentTime = time.time()
            while True:
                currentTime = time.time()
                b_button_gripper = GPIO.input(pin_btnRelease)
                if(b_button_gripper == True):
                    if((currentTime - startTime) >= 5):
                        isPress = rospy.get_param('/drop_mobile/isPressRelease')
                        if(isPress == False):
                            rospy.set_param('/drop_mobile/isPressRelease', True)
                        break
                else:
                    break
    while(b_button_gripper == True):
        b_button_gripper = GPIO.input(pin_btnRelease)
        if(b_button_gripper == False):
            break

def rpi_resume(req):
    GPIO.output(pin_relay, GPIO.HIGH)
    time.sleep(1)
    GPIO.output(pin_relay, GPIO.LOW)
    return {"success": True, "message": "rpi_resume"}


if __name__ == '__main__':
    try:
        rospy.init_node('rpi_btnMonitor')
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(pin_btnA, GPIO.IN)
        GPIO.setup(pin_btnB, GPIO.IN)
        GPIO.setup(pin_btnC, GPIO.IN)
        GPIO.setup(pin_btnD, GPIO.IN)
        GPIO.setup(pin_btnH, GPIO.IN)
        GPIO.setup(pin_btnL, GPIO.IN)
        GPIO.setup(pin_btnPower, GPIO.IN)
        GPIO.setup(pin_btnOperator, GPIO.IN)
        GPIO.setup(pin_btnRelease, GPIO.IN)
        GPIO.setup(pin_relay, GPIO.OUT)
        #GPIO.output(pin_relay, GPIO.HIGH)
        #time.sleep(1)
        #GPIO.output(pin_relay, GPIO.LOW)

        b_button_Power = GPIO.input(pin_btnPower)
        b_button_Operator = GPIO.input(pin_btnOperator)
        if(b_button_Operator == True):
                rospy.set_param('/drop_mobile/mode',"Operator")
                print("Mode: Operator")
        elif(b_button_Operator == False and b_button_Power == True):
                rospy.set_param('/drop_mobile/mode',"Customer")
                print("Mode: Customer")
        else:
                rospy.set_param('/drop_mobile/mode',"AutoRun")
                print("Mode: AutoRun")
        GPIO.add_event_detect(pin_btnA, GPIO.RISING, callback=button_A_callback, bouncetime=100)
        GPIO.add_event_detect(pin_btnB, GPIO.RISING, callback=button_B_callback, bouncetime=100)
        GPIO.add_event_detect(pin_btnC, GPIO.RISING, callback=button_C_callback, bouncetime=100)
        GPIO.add_event_detect(pin_btnD, GPIO.RISING, callback=button_D_callback, bouncetime=100)
        GPIO.add_event_detect(pin_btnH, GPIO.RISING, callback=button_H_callback, bouncetime=100)
        GPIO.add_event_detect(pin_btnL, GPIO.RISING, callback=button_L_callback, bouncetime=100)
        GPIO.add_event_detect(pin_btnPower, GPIO.BOTH, callback=button_Power_callback, bouncetime=2000)
        GPIO.add_event_detect(pin_btnOperator, GPIO.BOTH, callback=button_Operator_callback, bouncetime=1500)
        GPIO.add_event_detect(pin_btnRelease, GPIO.RISING, callback=gripper_release_callback,bouncetime=100)
        rospy.Service("/drop_mobile/rpi_resume", Trigger, rpi_resume)
        isOnline = rospy.get_param('/drop_mobile/isRpiOnline')
        if(isOnline == False):
            rospy.set_param('/drop_mobile/isRpiOnline', True)
            rospy.loginfo("Buttons can be pressed now !")
        rospy.spin()
    except rospy.ServiceException as e:
        rospy.logwarn(e)
    finally:
        GPIO.cleanup()



