------------------------------------------------------
--
-- ������
-- Author : YeoHyeonJoon (souled@ntl-inc.com)
--
------------------------------------------------------


Scene( 1, "TMQ 4 stage1" )

--���� ��ɱ��� ���
	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 14120)
	--]
	End()

--������ ���� �̵�
    Action( "point move" )
    --[
		Param( "loc x", 813.287)
		Param( "loc z", -875.261)
		Param( "run mode", 1 )
    --]
    End()
	
--���� ����
	Action( "direct play" )
	--[
		Param( "tblidx", 50044)
	--]     
	End()
	
	Action( "leave" )
	--[    
	--]
	End()  
	
End()


------------------------------------------------------