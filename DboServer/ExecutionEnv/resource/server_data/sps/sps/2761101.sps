------------------------------------------------------
--
-- �տ���
-- Author : YeoHyeonJoon (souled@ntl-inc.com)
--
------------------------------------------------------


Scene(1, "TMQ 4 stage1" )

--���� ��ɱ��� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 14110)
	--]
	End()

--������ ���� �̵�
    Action( "point move" )
    --[
		Param( "loc x", 826.559)
		Param( "loc z", -875.116)
		Param( "run mode", 1 )
    --]
    End()
	
--���� ����
	Action( "direct play" )
	--[
		Param( "tblidx", 50048)
	--]     
	End()
	
	Action( "leave" )
	--[    
	--]
	End()  

End()

------------------------------------------------------