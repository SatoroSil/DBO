Scene(1, "UD6 Ű�������� NPC ������ �����ϻ�")
--[
	--NPC�� UI�� �����ش�.
	Action("char condition")
	--[
		Param("ui disable", 1)
	--]
	End()
	
	--34012 WPS���� �̺�Ʈ�� �޴´�.
	Action("wait")
	--[
		Condition("recv event from wps")
		--[
			Param("wps index", 34012)
			Param("event id", 963)
		--]
		End()
	--]
	End()
	
	--NPC�� UI�� �����ش�.
	Action("char condition")
	--[
		Param("ui disable", 0)
	--]
	End()
	
	Action("sps end")
	--[
	
	--]
	End()

--]
End()