--ver01

Scene(1,"534")
--[
	Action("send event to wps")
	--[
		Param("wps index", 534)
		Param("event id", 205)
	--]
	End()

	Action("char condition")
	--[
		Param("ui disable", 1)
	--]
	End()

	Action("say")
	--[
		--ũ����! �߸��߾�. �ѹ��� ����~ �� ���� �ұ��� ���ݱ��� ���� �ٸ� ������ ���� �ȾҴٱ�.
		Param("tblidx", 3056)
	--]
	End()

	Action("direct play")
	--[
		Param("tblidx", 60023)
	--]
	End()

	Action("say")
	--[
		--���� ���� �ִ� ���� �ұݵ��� �� ���״ϱ� ���� �뼭����~ 
		Param("tblidx", 3057)
	--]
	End()

	Action("char condition")
	--[
		Param("ui disable", 0)
	--]
	End()

	Action("send event to wps")
	--[
		Param("wps index", 534)
		Param("event id", 62)
	--]
	End()

	Action("wait")
	--[
		Param("time", 3)
	--]
	End()

	Action("sps end")
	--[
	--]
	End()
--]
End()
