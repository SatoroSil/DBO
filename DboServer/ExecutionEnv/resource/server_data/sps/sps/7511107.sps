-- TMQ 2-1 Hard Mode


Scene(1, "TMQ 2-1" )
--[
	Action( "char condition" )
	--[
		Param( "ui disable", 1 )
	--]
	End()

	Action( "say" )
	--[
		Param( "tblidx", 3311 )
	--]
	End()
		
	Action( "wait" )
	--[
		Param( "time", 13 )
	--]
	End()
	
	Action( "say" )
	--[
		Param( "tblidx", 3306 )
	--]
	End()

	Action( "path move" )
	--[
		Param( "tblidx", 16 )
		Param( "run mode", 1 )
	--]
	End()

	Action( "say" )
	--[
		Param( "tblidx", 3307 )
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 13 )
	--]
	End()
	
	Action( "say" )
	--[
		Param( "tblidx", 3308 )
	--]
	End()
		
	Action( "path move" )
	--[
		Param( "tblidx", 21 )
		Param( "run mode", 1 )
	--]
	End()

	Action( "say" )
	--[
		Param( "tblidx", 3309 )
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 13 )
	--]
	End()

	Action( "say" )
	--[
		Param( "tblidx", 3310 )
	--]
	End()
	
	Action( "path move" )
	--[
		Param( "tblidx", 22 )
		Param( "run mode", 1 )
	--]
	End()
	
	-- tqs 12�κ��� ���
	Action( "send sps event" )
	--[
		Param( "event type", "tqs" )
		Param( "event id", 1003 )
	--]
	End()
	
 	Action( "wait" )
 	--[
 		Condition( "recv event from ts" )
 		--[
 			Param( "trigger type", "quest" )
 			Param( "event id", 1006 )
 		--]
 		End()
 	--]
 	End()
 	
 	Action( "direct play" )
	--[
		Param( "tblidx", 50044)
	--]     
	End()

	Action( "send event to wps" )
	--[
		Param( "wps index", 12101 )
		Param( "event id", 1041 )
	--]
	End()
		
	Action( "leave" )
	--[
	
	--]
	End()
		      
        Action( "sps end" )
        --[
        
        --]
        End()
--]
End()