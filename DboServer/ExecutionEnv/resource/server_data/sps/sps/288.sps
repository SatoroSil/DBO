--Ver02

Scene(1, "288")
--[

	Action( "wait" )
	--[
		Param( "event type", "ts" )
		Param( "event id", 9900 )
	--]
	End()

	Action( "say" )
	--[
		--"���!!!! �� ����. �� ���̴ٴ�"
		Param("tblidx", 3353)
	--]
	End()

	Action( "direct play" )
	--[
		Param( "tblidx", 60005 )
	--]
	End()

	Action( "say" )
	--[
		-- "ī��� �ΰ���!!"
		Param("tblidx", 3354)
	--]
	End()

	Action( "wait" )
	--[
		Param( "time", 2 )
	--]
	End()

	Action( "direct play" )
	--[
		Param( "tblidx", 60006 )
	--]
	End()

--]
End()
