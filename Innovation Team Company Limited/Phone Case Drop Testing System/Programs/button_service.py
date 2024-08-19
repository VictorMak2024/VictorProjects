#!/usr/bin/env python
from __future__ import print_function
from std_srvs.srv import Trigger
import rospy

class server:
    def __init__(self):
        rospy.Service('/button_pressed_A', Trigger, self.ButtonPress_A)
        rospy.Service('/button_pressed_B', Trigger, self.ButtonPress_B)
        rospy.Service('/button_pressed_C', Trigger, self.ButtonPress_C)
        rospy.Service('/button_pressed_D', Trigger, self.ButtonPress_D)
        rospy.Service('/button_pressed_H', Trigger, self.ButtonPress_H)
        rospy.Service('/button_pressed_L', Trigger, self.ButtonPress_L)
        rospy.Service('/button_pressed_AB', Trigger, self.ButtonPress_AB)
        rospy.Service('/button_pressed_CD', Trigger, self.ButtonPress_CD)
        rospy.Service('/button_pressed_HL', Trigger, self.ButtonPress_HL)
        rospy.Service('/button_pressed_gripper_release', Trigger, self.ButtonPress_Gripper_Release)

    def ButtonPress_A(self,req):
        print("Button A is pressed.")
        return {"success": True, "message":"Button A is pressed."}

    def ButtonPress_B(self,req):
        print("Button B is pressed.")
        return {"success": True, "message":"Button B is pressed."}
    
    def ButtonPress_C(self,req):
        print("Button C is pressed.")
        return {"success": True, "message":"Button C is pressed."}
    
    def ButtonPress_D(self,req):
        print("Button D is pressed.")
        return {"success": True, "message":"Button D is pressed."}
    
    def ButtonPress_H(self,req):
        print("Button H is pressed.")
        return {"success": True, "message":"Button H is pressed."}

    def ButtonPress_L(self,req):
        print("Button L is pressed.")
        return {"success": True, "message":"Button L is pressed."}

    def ButtonPress_AB(self,req):
        print("Button A & Button B are pressed.")
        return {"success": True, "message":"Button A & Button B are pressed."}

    def ButtonPress_CD(self,req):
        print("Button C & Button D are pressed.")
        return {"success": True, "message":"Button C & Button D are pressed."}

    def ButtonPress_HL(self,req):
        print("Button H & Button L are pressed.")
        return {"success": True, "message":"Button H & Button L are pressed."}

    def ButtonPress_Gripper_Release(self,req):
        print("The gripper is released.")
        return {"success": True, "message":"The gripper is released."}

if __name__ == "__main__":
   
    try:
        rospy.init_node("button")
        buttonserver = server()
	isOnline = rospy.get_param('/drop_mobile/isRpiOnline')
	if(isOnline == False):
		rospy.set_param('/drop_mobile/isRpiOnline', True)
        rospy.loginfo("Buttons can be pressed now !")
        rospy.spin()
    except rospy.ServiceException as e:
        rospy.logwarn(e)