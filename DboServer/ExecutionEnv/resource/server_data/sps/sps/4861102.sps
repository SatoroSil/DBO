Scene( 1, "34007" )
--[
-- ���� �����
	Action( "wait" )
	--[
		Condition( "recv event from wps" )
		--[
			Param( "wps index", 34007 )
			Param( "event id", 894 )
		--]
		End()
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 2 )
	--]
	End()			
		
	Action( "say" )
	--[
		Param( "tblidx", 3358 )
	--]
	End()	

-- lp 50 üũ �̺�Ʈ ��ٸ�
	Action( "wait" )
	--[
		Condition( "recv event from wps" )
		--[
			Param( "wps index", 34007 )
			Param( "event id", 895 )
		--]
		End()
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 2 )
	--]
	End()			
		
	Action( "say" )
	--[
		Param( "tblidx", 3359 )
	--]
	End()

-- lp 20 üũ
	Action( "wait" )
	--[
		Condition( "recv event from wps" )
		--[
			Param( "wps index", 34007 )
			Param( "event id", 896 )
		--]
		End()
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 2 )
	--]
	End()			
		
	Action( "say" )
	--[
		Param( "tblidx", 3360 )
	--]
	End()

-- ���� ���� �̺�Ʈ ��ٸ�
	Action( "wait" )
	--[
		Condition( "recv event from wps" )
		--[
			Param( "wps index", 34007 )
			Param( "event id", 901 )
		--]
		End()
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 0.5 )
	--]
	End()

	Action( "direct play" )
	--[
		Param( "tblidx", 60062 )
		Param( "event id", 899 )
		Param( "event type", "wps" )
	--]
	End()

	Action( "direct play" )
	--[
		Param( "tblidx", 60066 )
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 2 )
	--]
	End()			
		
	Action( "say" )
	--[
		Param( "tblidx", 3365 )
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 3 )
	--]
	End()			
		
	Action( "say" )
	--[
		Param( "tblidx", 3366 )
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 3 )
	--]
	End()			
		
	Action( "say" )
	--[
		Param( "tblidx", 3367 )
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 3 )
	--]
	End()			
		
	Action( "say" )
	--[
		Param( "tblidx", 3368 )
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 3 )
	--]
	End()

-- ���ߴٰ� �̺�Ʈ ��
	Action( "send event to wps" )
	--[
		Param( "wps index", 34007 )
		Param( "event id", 902 )
	--]
	End()

	Action( "sps end" )
	--[
	--]
	End()

--]
End()