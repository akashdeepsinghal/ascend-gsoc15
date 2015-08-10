import extpy;
browser = extpy.getbrowser()

import ascpy;

def Properties(Comp,Prop,PropType,TorP):
	import win32com.client
	dtlc = win32com.client.Dispatch("DTL.Thermodynamics.Calculator")
	dtlc.Initialize()
	if PropType=="constProp":
		PROP_VALUE = dtlc.GetCompoundConstProp(Comp,Prop)
	elif PropType=="constPDepProp":
		PROP_VALUE = dtlc.GetCompoundPDepProp(Comp,Prop,TorP)
	elif PropType=="constTDepProp":
		PROP_VALUE = dtlc.GetCompoundTDepProp(Comp,Prop,TorP)
	pv = float(PROP_VALUE)
	return pv

def CompProperty(Comp,Prop): #comp is the component and prop is the required property
	"""This function calls the DWSIM Thermodynamics DTL and gives the required component property"""
	import win32com.client
	dtlc = win32com.client.Dispatch("DTL.Thermodynamics.Calculator")
	dtlc.Initialize()
	print Comp
	print Prop

	PROP_VALUE = dtlc.GetCompoundConstProp(comp,prop)

	# pv = float(PROP_VALUE)
	print PROP_VALUE
	return PROP_VALUE
	
def TwoPhaseProperties(PropPack,FlashAlg,P,T,Comp1,Comp2,mf1,mf2,k,l2):
	import win32com.client
	dtlc = win32com.client.Dispatch("DTL.Thermodynamics.Calculator")
	dtlc.Initialize()
	Compounds=["12","12"]
	MoleFractions=[0.5,0.5]
	pv=[[1.0,1.0,1.0,1.0],[1.0,1.0,1.0,1.0],[1.0,1.0,1.0,1.0]]
	x=[[1.0,1.0,1.0,1.0],[1.0,1.0,1.0,1.0],[1.0,1.0,1.0,1.0]]
	Compounds[0]=Comp1
	Compounds[1]=Comp2
	MoleFractions[0]=mf1
	MoleFractions[1]=mf2
	FlashAlg=int(FlashAlg)
	val=dtlc.PTFlash(PropPack, FlashAlg, P, T,Compounds, MoleFractions)
	pv[0] = val[1]
	pv[1]=  val[2]
	pv[2]=  val[3]
	
	for i in range(3):
		for j in range(4):
			x[i][j]=float(pv[i][j])
	return x[k][l2]

def BinaryInteractionParameters(PropPack,Comp1,Comp2,l2):
	import win32com.client
	dtlc = win32com.client.Dispatch("DTL.Thermodynamics.Calculator")
	dtlc.Initialize()
	
	x=[1.0,1.0,1.0]

	l2=int(l2)
	
	val=dtlc.GetInteractionParameterSet(PropPack,Comp1,Comp2)
	
	for i in range(3):
		x[i]=float(val[i])
	return x[l2]

#!/usr/bin/python
def antoine(CompGiven,i):
    from xml.dom.minidom import parse
    import xml.dom.minidom
    # Open XML document using minidom parser
    DOMTree = xml.dom.minidom.parse("I:\Project\Modelica_DWSIM/chemsep1.xml")
    compounds = DOMTree.documentElement
    """if collection.hasAttribute("shelf"):
            print "Root element : %s" % collection.getAttribute("shelf")"""
    
    # Get all the compounds
    compound = compounds.getElementsByTagName("compound")
    for comp in compound:
           compName=comp.getElementsByTagName("CompoundID")[0]
           x=[1,1,1,1,1]
           val=compName
           if compName.getAttribute("value")==CompGiven:
               xyz=comp.getElementsByTagName("VaporPressure")[0]
               A=float(xyz.getElementsByTagName("A")[0].getAttribute("value"))
               B=float(xyz.getElementsByTagName("B")[0].getAttribute("value"))
               C=float(xyz.getElementsByTagName("C")[0].getAttribute("value"))
               D=float(xyz.getElementsByTagName("D")[0].getAttribute("value"))
               E=float(xyz.getElementsByTagName("E")[0].getAttribute("value"))
               x[0]=A
               x[1]=B
               x[2]=C
               x[3]=D
               x[4]=E
               return x[i]


extpy.registermethod(CompProperty)