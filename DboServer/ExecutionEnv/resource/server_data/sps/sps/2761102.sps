------------------------------------------------------
--
-- �տ���
-- Author : YeoHyeonJoon (souled@ntl-inc.com)
--
------------------------------------------------------


Scene(1, "TMQ 2 �տ���" )

--�տ��� �����ɱ��� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 12070)
	--]
	End()
	
--�տ��� ������ ���� �̵�
    Action( "point move" )
    --[
		Param( "loc x", -1148.90)
		Param( "loc z", 856.13)
		Param( "run mode", 1 )
    --]
    End()
	
--�տ��� ���� ����
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
	
	
Scene(2, "TMQ 2 �տ���" )

--�տ��� �����ɱ��� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 12360)
	--]
	End()
	
--�տ��� ������ ���� �̵�
    Action( "point move" )
    --[
		Param( "loc x", 965.07)
		Param( "loc z", -398.99)
		Param( "run mode", 1 )
    --]
    End()
	
--�տ��� ���� ����
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


Scene(4, "TMQ 2 �տ���" )

	Action( "direct play" )
	--[
		Param( "tblidx", 50012)
	--]     
	End()

End()

------------------------------------------------------
