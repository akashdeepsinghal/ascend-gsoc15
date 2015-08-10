import win32com.client
dtlc = win32com.client.Dispatch("DTL.Thermodynamics.Calculator")
dtlc.Initialize()
def Properties(Comp,Prop,PropType,TorP):
	import win32com.client
	dtlc = win32com.client.Dispatch("DTL.Thermodynamics.Calculator")
	dtlc.Initialize()
	if PropType=="constProp":
		PROP_VALUE = dtlc.GetCompoundConstProp(Comp,Prop)
	elif PropType=="constPDepProp":
		TorP=float(TorP)
		PROP_VALUE = dtlc.GetCompoundPDepProp(Comp,Prop,TorP)
	elif PropType=="constTDepProp":
		TorP=float(TorP)
		PROP_VALUE = dtlc.GetCompoundTDepProp(Comp,Prop,TorP)
	pv = float(PROP_VALUE)
	return pv
def TwoPhaseProperties(PropPack,FlashAlg,P,T,Comp1,Comp2,mf1,mf2,k,l2):
	import win32com.client
	dtlc = win32com.client.Dispatch("DTL.Thermodynamics.Calculator")
	dtlc.Initialize()
	Compounds=["12","12"]
	MoleFractions=["12","12"]
	pv=[[1.0,1.0,1.0,1.0],[1.0,1.0,1.0,1.0],[1.0,1.0,1.0,1.0]]
	x=[[1.0,1.0,1.0,1.0],[1.0,1.0,1.0,1.0],[1.0,1.0,1.0,1.0]]
	Compounds[0]=Comp1
	Compounds[1]=Comp2
	MoleFractions[0]=mf1
	MoleFractions[1]=mf2
	FlashAlg=float(FlashAlg)
	P=float(P)
	T=float(T)
	l=len(MoleFractions)
	for i in range(l):
		MoleFractions[i]=float(MoleFractions[i])
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
