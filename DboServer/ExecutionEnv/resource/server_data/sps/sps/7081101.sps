------------------------------------------------------
--
-- TMQ1-3 ���ڴ� ����, TMQ1-4 �̶� ����
-- Author : YeoHyeonJoon (souled@ntl-inc.com)
--
------------------------------------------------------


Scene( 1, "TMQ 3 ���ڴ� ����" )

--���ڴ� ����
	Action( "sitdown" )
	--[
		Param( "sitdown", "true")
	--]
	End()

	Action( "wait" )
	--[
		Param("event type", "tqs")
		Param( "event id", 13202)
	--]
	End()

--�Ͼ
	Action( "sitdown" )
	--[
		Param( "sitdown", "false")
	--]
	End()	

--���
	Action( "wait" )
	--[
		Param("time", 2 )
	--]
	End()
	
--�Ͼ �˸�
	Action( "send sps event" )
	--[
		Param( "event type", "tqs" ) 
		Param( "event id", 13203 )
	--]
	End()
	
--���̴��
	Action( "wait" )
	--[
		Param("event type", "ts")
		Param( "event id", 11020)
	--]
	End()

End()
	
	
------------------------------------------------------


Scene( 2, "TMQ 3 ����� ����" )

    Action( "path move" )
    --[
        Param( "tblidx", 4)
        Param( "run mode", 1 )
    --]
    End()

	Action( "sps end" )
	--[
	--]
	End()
	
End()
------------------------------------------------------

Scene( 3,"TMQ 1-4 �̶� ����" )

   Action( "direct play" )
   --[
	Param( "tblidx", 1046)
   --]
   End()

End()

------------------------------------------------------