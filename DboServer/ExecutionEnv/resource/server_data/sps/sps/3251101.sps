------------------------------------------------------
--
-- �ҷ��� ������
-- Author : YeoHyeonJoon (souled@ntl-inc.com)
--
------------------------------------------------------

Scene( 1, "TLQ 3 ���� �����" )

--���
	Action( "wait" )
	--[
		Param( "time", 5 )
	--]
	End()

--�ɾ��ֱ�
	Action( "sitdown" )
	--[
		Param( "sitdown", "true")
	--]
	End()
	
--����Ű�� ��ɱ��� ���
	Action( "wait" )
	--[
		Condition("recv event from ts")
		--[
			Param( "trigger type", "quest")
			Param( "event id", 16710)
		--]
		End()
	--]
	End()
	
--�Ͼ
	Action( "sitdown" )
	--[
		Param( "sitdown", "false")
	--]
	End()
	
	Action( "sps end" )
	--[
	--]
	End()

End()

Scene( 2, "TLQ 3 �θ� ������ ������" )

    Action( "point move" )
    --[
		Param( "loc x", -74.77)
		Param( "loc z", -1.25)
		Param( "run mode", 1 )
    --]
    End()
	
    Action( "point move" )
    --[
		Param( "loc x", -79.93)
		Param( "loc z", 1.03)
		Param( "run mode", 1 )
    --]
    End()
	
	Action( "sps end" )
	--[
	--]
	End() 

End()