------------------------------------------------------
--
-- ����
-- Author : YeoHyeonJoon (souled@ntl-inc.com)
--
------------------------------------------------------


Scene( 1, "TLQ 2 ������ ����" )

--������ ��� Idle
	
--���
	Action( "wait" )
	--[
		Param("event type", "ts")
		Param( "event id", 16520)
	--]
	End()
	
--�Ͼ�� ����
	Action( "direct play" )
	--[
		Param( "tblidx", 50000)
	--]     
	End()

--2�� Delay
	Action( "wait" )
	--[
		Param( "time", 2 )
	--]
	End()

--�Ͼ �־��
	Action( "direct play" )
	--[
		Param( "tblidx", 50031)
	--]     
	End()
	
--��
	Action("sps end")
	--[
	--]
	End()
	
End()


------------------------------------------------------