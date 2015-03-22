encounters = 0
light = Poke:GetLightLevel()
Poke:Println("light:" .. tostring(light))

function isScreenOn()
	return Poke:GetLightLevel() > light - 30
end


function hunt()
	Poke:Push("X", 160)
	Poke:Push("A", 160)
	Poke:Sleep(800)
	if isScreenOn() then
		Poke:Push("B", 200)
		return
	else
		Poke:Sleep(800)
		Poke:Push("A", 160)
		Poke:Push("Down", 160)
		Poke:Push("A", 160)
		Poke:Push("A", 160)
		check()
	end
end

function check()
	--Wait to see if screen has turned back on
	Poke:Sleep(4000)
	if isScreenOn() then
		Poke:Push("B", 200)
		Poke:Sleep(1000)
		Poke:Push("B", 200)
		Poke:Sleep(2000)
		Poke:Push("B", 200)
		Poke:Sleep(3000)
		hunt()
	else
		Poke:Sleep(15700)
		Poke:Println("light value:" .. tostring(Poke:GetLightLevel()))
		encounters = encounters + 1
		Poke:Println("Encounters: " .. tostring(encounters))
		
		--If screen is on, then return to hunting
		if isScreenOn() then
			Poke:Push("Down", 200)
			Poke:Push("Right", 200)
			Poke:Push("A", 160)
			Poke:Sleep(4600)
			if isScreenOn() then
				Poke:Push("B", 200)
				Poke:Sleep(1000)
				Poke:Push("B", 200)
				Poke:Sleep(1000)
				Poke:Push("Left", 200)
				Poke:Push("A", 200)
				Poke:Sleep(6600)
			else
			Poke:Sleep(2000)
			end
		else
			--If screen is still off, then we have a shiny
			Poke:Println("Found a Shiny!!!")
			while true do
				--Loop FOREVER!!!!
			end
		end
	end
end




while true do
	hunt()
end