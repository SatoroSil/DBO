
Scene(1, "1013")
--[
	Action( "char condition" )
	--[
		Param( "ui disable", 1 )
	--]
	End()

	Action( "wait" )
	--[
		Condition( "recv event from wps" )
		--[
			Param( "wps index", 1013 )
			Param( "event id", 101301 )
		--]
		End()
	--]
	End()

	Action( "path move" )
	--[
		Param( "tblidx", 1013 )
		Param( "run mode", 1 )
	--]
	End()
	
	Action( "say" )
	--[
        	--"���� ������. �̰� ����."
		Param( "tblidx" , 3315 )               
	--]     
	End()
	
	Action( "wait" )
	--[
		Param( "time", 2 )    
	--]
	End()

	Action( "say" )
	--[
        	-- "���� �ٽô� �̰� �Գ� ����." 
		Param( "tblidx" , 3316 )              
	--]     
	End()
	
	Action( "wait" )
	--[
		Param( "time", 2 )    
	--]
	End()
	
	Action( "send event to wps" )
	--[
		Param( "wps index", 1013 )
		Param( "event id", 101302 )
	--]
	End()
		
	Action( "leave" )
	--[
	
	--]
	End()
--]
End()	
	
	
	
	
	
	
	