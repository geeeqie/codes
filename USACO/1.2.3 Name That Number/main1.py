trans_to_letter={'2':['A','B','C'],'3':['D','E','F'],'4':['G','H','I'],'5':['J','K','L'],'6':['M','N','O'],'7':['P','R','S'],'8':['T','U','V'],'9':['W','X','Y']}

def load_names():
	inFile = open("dict.txt")
	namelist={}
	for line in inFile:
		namelist[line.strip()]=1
	return namelist


def get_name(number_seq):
	prob_name=[]
	if len(number_seq)==1:
		prob_name=trans_to_letter[number_seq]
	else:
		sub_prob_name=get_name(number_seq[1:])
		first_num_list=trans_to_letter[number_seq[0]]
		for e in first_num_list:
			prob_name+=map(lambda x:e+x,sub_prob_name)
	return prob_name

number_seq=raw_input()
namelist=load_names()
prob_name=get_name(number_seq)
is_in =False
for e in prob_name:
	if namelist.get(e,0)==1:
		print e
		is_in=True
if is_in==False:
	print 'NONE'
