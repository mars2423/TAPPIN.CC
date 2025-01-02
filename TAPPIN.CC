local MacLib = loadstring(game:HttpGet("https://github.com/biggaboy212/Maclib/releases/latest/download/maclib.txt"))()

local Window = MacLib:Window({
	Title = "Tappin.cc",
	Subtitle = "for fake da hoods.",
	Size = UDim2.fromOffset(868, 650),
	DragStyle = 2,
	DisabledWindowControls = {},
	ShowUserInfo = true,
	Keybind = Enum.KeyCode.RightControl,
	AcrylicBlur = true,
})

local globalSettings = {
	UIBlurToggle = Window:GlobalSetting({
		Name = "UI Blur",
		Default = Window:GetAcrylicBlurState(),
		Callback = function(bool)
			Window:SetAcrylicBlurState(bool)
			Window:Notify({
				Title = Window.Settings.Title,
				Description = (bool and "Enabled" or "Disabled") .. " UI Blur",
				Lifetime = 5
			})
		end,
	}),
	NotificationToggler = Window:GlobalSetting({
		Name = "Notifications",
		Default = Window:GetNotificationsState(),
		Callback = function(bool)
			Window:SetNotificationsState(bool)
			Window:Notify({
				Title = Window.Settings.Title,
				Description = (bool and "Enabled" or "Disabled") .. " Notifications",
				Lifetime = 5
			})
		end,
	}),
	ShowUserInfo = Window:GlobalSetting({
		Name = "Show User Info",
		Default = Window:GetUserInfoState(),
		Callback = function(bool)
			Window:SetUserInfoState(bool)
			Window:Notify({
				Title = Window.Settings.Title,
				Description = (bool and "Showing" or "Redacted") .. " User Info",
				Lifetime = 5
			})
		end,
	})
}

local tabGroups = {
	TabGroup1 = Window:TabGroup()
}

local tabs = {
	Main = tabGroups.TabGroup1:Tab({ Name = "silent aim", Image = "rbxassetid://18821914323" }),
	Main2 = tabGroups.TabGroup1:Tab({ Name = "camlock", Image = "rbxassetid://10709789686" }),
	Visual = tabGroups.TabGroup1:Tab({ Name = "visual", Image = "rbxassetid://10723346871" }),
	Player = tabGroups.TabGroup1:Tab({ Name = "player", Image = "rbxassetid://10747373426" }),
}

local sections = {
	MainSection1 = tabs.Main:Section({ Side = "Left" }),
	Main2 = tabs.Main2:Section({ Side = "Left" }),
	Playersect1 = tabs.Player:Section({ Side = "Left" }),
	Visualsect1 = tabs.Visual:Section({ Side = "Left" }),
}

sections.MainSection1:Header({
	Name = "silent aim"
})

sections.Main2:Header({
	Name = "camlock🤡"
})

sections.Visualsect1:Header({
	Name = "ESP"
})

sections.MainSection1:Button({
	Name = "silent aim unstreamable",
	Callback = function()
		Window:Dialog({
			Title = Window.Settings.Title,
			Description = "cannt turn off rejoin to turn off",
			Buttons = {
				{
					Name = "Confirm",
					Callback = function()
						getgenv().SilentAim = {
							Settings = {
								Enabled = true,
								AimPart = "UpperTorso",
								Prediction = 0.165,
								WallCheck = true
							},
							FOV = {
								Enabled = true,
								Size = 110,
								Filled = false,
								Thickness = 0.66,
								Transparency = 10,
								Color = Color3.fromHSV(tick() % 5 / 5, 1, 1)
							}
						}
						local lp = game:GetService("Players").LocalPlayer
						local cc = game:GetService("Workspace").CurrentCamera
						local mouse = lp:GetMouse()
						getgenv().PredictionBackUp = getgenv().SilentAim.Settings.Prediction
						local cc = game:GetService("Workspace").CurrentCamera
						local mouse = lp:GetMouse()
						
						local Utility = {
							Invite = "camlock",
							BackupInvite = "closetcheating",
							Version = "1.0.0a",
							Method = "UpdateMousePos",
							AllowedPlaceIDs = {
								2788229376, -- Da Hood
								7213786345, -- Da Hood VC
								9825515356, -- Hood Customs
								5602055394, -- Hood Modded
								7951883376, -- Hood Modded VC
								12927359803, -- Dah Aim Trainer
								12867571492, -- KatanaHood
								7242996350, -- Da Hood Aim Trainer
								12884917481, -- Da Hood Aim Trainer VC
								11867820563, -- Dae Hood
								12618586930, -- Dat Hood
							}
						}
						
						if game.PlaceId == 2788229376 or game.PlaceId == 7213786345 then -- // Da Hood
							Utility.Method = "UpdateMousePos"
								MainRemote = game:GetService("ReplicatedStorage").MainEvent
						elseif game.PlaceId == 5602055394 or game.PlaceId == 7951883376 then -- // Hood Modded
							Utility.Method = "MousePos"
								MainRemote = game:GetService("ReplicatedStorage").Bullets 
						elseif game.PlaceId == 12927359803 then -- // Dah Aim Trainer
							Utility.Method = "UpdateMousePos"
								MainRemote = game:GetService("ReplicatedStorage").MainEvent
						elseif game.PlaceId == 7242996350 or game.PlaceId == 12884917481 then -- // Da Hood Aim Trainer
							Utility.Method = "UpdateMousePos" 
								MainRemote = game:GetService("ReplicatedStorage").MainEvent
						elseif game.PlaceId == 12867571492 then -- // Katana Hood
							Utility.Method = "UpdateMousePos"
								MainRemote = game:GetService("ReplicatedStorage").MainEvent
						elseif game.PlaceId == 11867820563 then -- // Dae Hood
							Utility.Method = "UpdateMousePos"
								MainRemote = game:GetService("ReplicatedStorage").MainEvent
						elseif game.PlaceId == 12618586930 then -- // Dat Hood
							Utility.Method = "UpdateMousePos"
								MainRemote = game:GetService("ReplicatedStorage").MainEvent
						end
						
						WTS = (function(Object)
							local ObjectVector = cc:WorldToScreenPoint(Object.Position)
							return Vector2.new(ObjectVector.X, ObjectVector.Y)
						end)
						
						Filter = (function(obj)
							if (obj:IsA('BasePart')) then
								return true
							end
						end)
						
						mousePosVector2 = (function()
							return Vector2.new(mouse.X, mouse.Y) 
						end)
						
						getClosestBodyPart = (function()
							local shortestDistance = math.huge
							local bodyPart = nil
							for _, v in next, game.Players:GetPlayers() do
								if (v ~= lp and v.Character and v.Character:FindFirstChild("Humanoid")) then
									for k, x in next, v.Character:GetChildren() do
										if (Filter(x)) then
											local Distance = (WTS(x) - mousePosVector2()).magnitude
											if (Distance < shortestDistance) then
												shortestDistance = Distance
												bodyPart = x
											end
										end
									end
								end
							end
							return bodyPart
						end)
						local FOVCircle = Drawing.new("Circle")
						function updateFOV()
							FOVCircle.Radius = SilentAim.FOV.Size * 3
							FOVCircle.Visible = SilentAim.FOV.Enabled
							FOVCircle.Transparency = SilentAim.FOV.Transparency
							FOVCircle.Filled = SilentAim.FOV.Filled
							FOVCircle.Color = SilentAim.FOV.Color
							FOVCircle.Thickness = SilentAim.FOV.Thickness
							FOVCircle.Position = Vector2.new(game:GetService("UserInputService"):GetMouseLocation().X, game:GetService("UserInputService"):GetMouseLocation().Y)
							return FOVCircle
						end
						
						local plrService = game:GetService("Players")
						local localPlr = plrService.LocalPlayer
						local mouseLocal = localPlr:GetMouse()
						local Players, Client, Mouse, Camera =
							game:GetService("Players"),
							game:GetService("Players").LocalPlayer,
							game:GetService("Players").LocalPlayer:GetMouse(),
							game:GetService("Workspace").CurrentCamera
						
						
						function wallCheck(destination, ignore)
							if (getgenv().SilentAim.Settings.WallCheck) then
								local Origin = Camera.CFrame.p
								local CheckRay = Ray.new(Origin, destination - Origin)
								local Hit = game:GetService("Workspace"):FindPartOnRayWithIgnoreList(CheckRay, ignore)
								return Hit == nil
							else
								return true
							end
						end
						
						function getClosestPlayerToCursor()
							closestDist = SilentAim.FOV.Size * 3.47
							closestPlr = nil;
							for i, v in next, plrService:GetPlayers() do
								pcall(function()
									local notKO = v.Character:WaitForChild("BodyEffects")["K.O"].Value ~= true;
									local notGrabbed = v.Character:FindFirstChild("GRABBING_COINSTRAINT") == nil
									if v ~= localPlr and v.Character and v.Character.Humanoid.Health > 0 and notKO and notGrabbed then
										local screenPos, cameraVisible = Camera:WorldToViewportPoint(v.Character.HumanoidRootPart.Position)
										if cameraVisible then
											local distToMouse = (Vector2.new(mouseLocal.X, mouseLocal.Y) - Vector2.new(screenPos.X, screenPos.Y)).Magnitude
											if distToMouse < closestDist and wallCheck(v.Character.Head.Position, {
												game:GetService("Players").LocalPlayer,
												v.Character
											}) then
												closestPlr = v
												closestDist = distToMouse
											end
										end
									end
								end)
							end
							return closestPlr, closestDist
						end
						
						spawn(function()
							while wait() do
								Plr = getClosestPlayerToCursor()
							end
						end)
						
						spawn(function()
							while wait() do
								if Plr ~= nil and Plr.Character.Humanoid.FloorMaterial ~= Enum.Material.Air then
									local Ping = math.floor(game.Stats.Network.ServerStatsItem["Data Ping"]:GetValue())
									getgenv().SilentAim.Settings.Prediction = Ping / 1000 + 0.07
								end
							end
						end)
						
						game:GetService("RunService").Heartbeat:connect(function()
							updateFOV()
						end)
						
						game.Players.LocalPlayer.Character.ChildAdded:Connect(function(tool)
							if tool:IsA("Tool") then -- add a better check for if the tool is a weapon 
								tool.Activated:Connect(function() -- fuck a :Disconnect lol
									if Plr ~= nil then
										game:GetService("ReplicatedStorage").MainEvent:FireServer(Utility.Method, Plr.Character[SilentAim.Settings.AimPart].Position + (Plr.Character[SilentAim.Settings.AimPart].Velocity * SilentAim.Settings.Prediction))
									end
								end)
							end
						end)
					end,
				},
				{
					Name = "Cancel"
				}
			}
		})
	end,
})

sections.MainSection1:Button({
	Name = "silent aim streamable",
	Callback = function()
		Window:Dialog({
			Title = Window.Settings.Title,
			Description = "cannt turn off rejoin to turn off",
			Buttons = {
				{
					Name = "Confirm",
					Callback = function()
						getgenv().SilentAim = {
							Settings = {
								Enabled = true,
								AimPart = "UpperTorso",
								Prediction = 0.165,
								WallCheck = true
							},
							FOV = {
								Enabled = true,
								Size = 75,
								Filled = false,
								Thickness = 0.66,
								Transparency = 0.0,
								Color = Color3.fromHSV(tick() % 5 / 5, 1, 1)
							}
						}
						local lp = game:GetService("Players").LocalPlayer
						local cc = game:GetService("Workspace").CurrentCamera
						local mouse = lp:GetMouse()
						getgenv().PredictionBackUp = getgenv().SilentAim.Settings.Prediction
						local cc = game:GetService("Workspace").CurrentCamera
						local mouse = lp:GetMouse()
						
						local Utility = {
							Invite = "camlock",
							BackupInvite = "closetcheating",
							Version = "1.0.0a",
							Method = "UpdateMousePos",
							AllowedPlaceIDs = {
								2788229376, -- Da Hood
								7213786345, -- Da Hood VC
								9825515356, -- Hood Customs
								5602055394, -- Hood Modded
								7951883376, -- Hood Modded VC
								12927359803, -- Dah Aim Trainer
								12867571492, -- KatanaHood
								7242996350, -- Da Hood Aim Trainer
								12884917481, -- Da Hood Aim Trainer VC
								11867820563, -- Dae Hood
								12618586930, -- Dat Hood
							}
						}
						
						if game.PlaceId == 2788229376 or game.PlaceId == 7213786345 then -- // Da Hood
							Utility.Method = "UpdateMousePos"
								MainRemote = game:GetService("ReplicatedStorage").MainEvent
						elseif game.PlaceId == 5602055394 or game.PlaceId == 7951883376 then -- // Hood Modded
							Utility.Method = "MousePos"
								MainRemote = game:GetService("ReplicatedStorage").Bullets 
						elseif game.PlaceId == 12927359803 then -- // Dah Aim Trainer
							Utility.Method = "UpdateMousePos"
								MainRemote = game:GetService("ReplicatedStorage").MainEvent
						elseif game.PlaceId == 7242996350 or game.PlaceId == 12884917481 then -- // Da Hood Aim Trainer
							Utility.Method = "UpdateMousePos" 
								MainRemote = game:GetService("ReplicatedStorage").MainEvent
						elseif game.PlaceId == 12867571492 then -- // Katana Hood
							Utility.Method = "UpdateMousePos"
								MainRemote = game:GetService("ReplicatedStorage").MainEvent
						elseif game.PlaceId == 11867820563 then -- // Dae Hood
							Utility.Method = "UpdateMousePos"
								MainRemote = game:GetService("ReplicatedStorage").MainEvent
						elseif game.PlaceId == 12618586930 then -- // Dat Hood
							Utility.Method = "UpdateMousePos"
								MainRemote = game:GetService("ReplicatedStorage").MainEvent
						end
						
						WTS = (function(Object)
							local ObjectVector = cc:WorldToScreenPoint(Object.Position)
							return Vector2.new(ObjectVector.X, ObjectVector.Y)
						end)
						
						Filter = (function(obj)
							if (obj:IsA('BasePart')) then
								return true
							end
						end)
						
						mousePosVector2 = (function()
							return Vector2.new(mouse.X, mouse.Y) 
						end)
						
						getClosestBodyPart = (function()
							local shortestDistance = math.huge
							local bodyPart = nil
							for _, v in next, game.Players:GetPlayers() do
								if (v ~= lp and v.Character and v.Character:FindFirstChild("Humanoid")) then
									for k, x in next, v.Character:GetChildren() do
										if (Filter(x)) then
											local Distance = (WTS(x) - mousePosVector2()).magnitude
											if (Distance < shortestDistance) then
												shortestDistance = Distance
												bodyPart = x
											end
										end
									end
								end
							end
							return bodyPart
						end)
						local FOVCircle = Drawing.new("Circle")
						function updateFOV()
							FOVCircle.Radius = SilentAim.FOV.Size * 3
							FOVCircle.Visible = SilentAim.FOV.Enabled
							FOVCircle.Transparency = SilentAim.FOV.Transparency
							FOVCircle.Filled = SilentAim.FOV.Filled
							FOVCircle.Color = SilentAim.FOV.Color
							FOVCircle.Thickness = SilentAim.FOV.Thickness
							FOVCircle.Position = Vector2.new(game:GetService("UserInputService"):GetMouseLocation().X, game:GetService("UserInputService"):GetMouseLocation().Y)
							return FOVCircle
						end
						
						local plrService = game:GetService("Players")
						local localPlr = plrService.LocalPlayer
						local mouseLocal = localPlr:GetMouse()
						local Players, Client, Mouse, Camera =
							game:GetService("Players"),
							game:GetService("Players").LocalPlayer,
							game:GetService("Players").LocalPlayer:GetMouse(),
							game:GetService("Workspace").CurrentCamera
						
						
						function wallCheck(destination, ignore)
							if (getgenv().SilentAim.Settings.WallCheck) then
								local Origin = Camera.CFrame.p
								local CheckRay = Ray.new(Origin, destination - Origin)
								local Hit = game:GetService("Workspace"):FindPartOnRayWithIgnoreList(CheckRay, ignore)
								return Hit == nil
							else
								return true
							end
						end
						
						function getClosestPlayerToCursor()
							closestDist = SilentAim.FOV.Size * 3.47
							closestPlr = nil;
							for i, v in next, plrService:GetPlayers() do
								pcall(function()
									local notKO = v.Character:WaitForChild("BodyEffects")["K.O"].Value ~= true;
									local notGrabbed = v.Character:FindFirstChild("GRABBING_COINSTRAINT") == nil
									if v ~= localPlr and v.Character and v.Character.Humanoid.Health > 0 and notKO and notGrabbed then
										local screenPos, cameraVisible = Camera:WorldToViewportPoint(v.Character.HumanoidRootPart.Position)
										if cameraVisible then
											local distToMouse = (Vector2.new(mouseLocal.X, mouseLocal.Y) - Vector2.new(screenPos.X, screenPos.Y)).Magnitude
											if distToMouse < closestDist and wallCheck(v.Character.Head.Position, {
												game:GetService("Players").LocalPlayer,
												v.Character
											}) then
												closestPlr = v
												closestDist = distToMouse
											end
										end
									end
								end)
							end
							return closestPlr, closestDist
						end
						
						spawn(function()
							while wait() do
								Plr = getClosestPlayerToCursor()
							end
						end)
						
						spawn(function()
							while wait() do
								if Plr ~= nil and Plr.Character.Humanoid.FloorMaterial ~= Enum.Material.Air then
									local Ping = math.floor(game.Stats.Network.ServerStatsItem["Data Ping"]:GetValue())
									getgenv().SilentAim.Settings.Prediction = Ping / 1000 + 0.07
								end
							end
						end)
						
						game:GetService("RunService").Heartbeat:connect(function()
							updateFOV()
						end)
						
						game.Players.LocalPlayer.Character.ChildAdded:Connect(function(tool)
							if tool:IsA("Tool") then -- add a better check for if the tool is a weapon 
								tool.Activated:Connect(function() -- fuck a :Disconnect lol
									if Plr ~= nil then
										game:GetService("ReplicatedStorage").MainEvent:FireServer(Utility.Method, Plr.Character[SilentAim.Settings.AimPart].Position + (Plr.Character[SilentAim.Settings.AimPart].Velocity * SilentAim.Settings.Prediction))
									end
								end)
							end
						end)
					end,
				},
				{
					Name = "Cancel"
				}
			}
		})
	end,
})



sections.MainSection1:Divider()

sections.MainSection1:Header({
	Text = "what is silent aim?"
})

sections.MainSection1:Paragraph({
	Header = "silent aim",
	Body = "silent aim is when the target is in ur fov it moves ur bullet to the enemey silghtly unstreamable looks legit unstreamable ur bullets go everywhere "
})


sections.Main2:Button({
	Name = "camlock (q)",
	Callback = function()
		Window:Dialog({
			Title = Window.Settings.Title,
			Description = "camera traces target",
			Buttons = {
				{
					Name = "Confirm",
					Callback = function()
						getgenv().OldAimPart = "HumanoidRootPart"
getgenv().AimPart = "HumanoidRootPart" -- For R15 Games: {UpperTorso, LowerTorso, HumanoidRootPart, Head} | For R6 Games: {Head, Torso, HumanoidRootPart}  
    getgenv().AimlockKey = "q"
    getgenv().AimRadius = 30 -- How far away from someones character you want to lock on at
    getgenv().ThirdPerson = true 
    getgenv().FirstPerson = true
    getgenv().TeamCheck = false -- Check if Target is on your Team (True means it wont lock onto your teamates, false is vice versa) (Set it to false if there are no teams)
    getgenv().PredictMovement = true -- Predicts if they are moving in fast velocity (like jumping) so the aimbot will go a bit faster to match their speed 
    getgenv().PredictionVelocity = 6.612
    getgenv().CheckIfJumped = true
    getgenv().Smoothness = false
    getgenv().SmoothnessAmount = 0.2

    local Players, Uis, RService, SGui = game:GetService"Players", game:GetService"UserInputService", game:GetService"RunService", game:GetService"StarterGui";
    local Client, Mouse, Camera, CF, RNew, Vec3, Vec2 = Players.LocalPlayer, Players.LocalPlayer:GetMouse(), workspace.CurrentCamera, CFrame.new, Ray.new, Vector3.new, Vector2.new;
    local Aimlock, MousePressed, CanNotify = true, false, false;
    local AimlockTarget;
    local OldPre;
    

    
    getgenv().WorldToViewportPoint = function(P)
        return Camera:WorldToViewportPoint(P)
    end
    
    getgenv().WorldToScreenPoint = function(P)
        return Camera.WorldToScreenPoint(Camera, P)
    end
    
    getgenv().GetObscuringObjects = function(T)
        if T and T:FindFirstChild(getgenv().AimPart) and Client and Client.Character:FindFirstChild("Head") then 
            local RayPos = workspace:FindPartOnRay(RNew(
                T[getgenv().AimPart].Position, Client.Character.Head.Position)
            )
            if RayPos then return RayPos:IsDescendantOf(T) end
        end
    end
    
    getgenv().GetNearestTarget = function()
        -- Credits to whoever made this, i didnt make it, and my own mouse2plr function kinda sucks
        local players = {}
        local PLAYER_HOLD  = {}
        local DISTANCES = {}
        for i, v in pairs(Players:GetPlayers()) do
            if v ~= Client then
                table.insert(players, v)
            end
        end
        for i, v in pairs(players) do
            if v.Character ~= nil then
                local AIM = v.Character:FindFirstChild("Head")
                if getgenv().TeamCheck == true and v.Team ~= Client.Team then
                    local DISTANCE = (v.Character:FindFirstChild("Head").Position - game.Workspace.CurrentCamera.CFrame.p).magnitude
                    local RAY = Ray.new(game.Workspace.CurrentCamera.CFrame.p, (Mouse.Hit.p - game.Workspace.CurrentCamera.CFrame.p).unit * DISTANCE)
                    local HIT,POS = game.Workspace:FindPartOnRay(RAY, game.Workspace)
                    local DIFF = math.floor((POS - AIM.Position).magnitude)
                    PLAYER_HOLD[v.Name .. i] = {}
                    PLAYER_HOLD[v.Name .. i].dist= DISTANCE
                    PLAYER_HOLD[v.Name .. i].plr = v
                    PLAYER_HOLD[v.Name .. i].diff = DIFF
                    table.insert(DISTANCES, DIFF)
                elseif getgenv().TeamCheck == false and v.Team == Client.Team then 
                    local DISTANCE = (v.Character:FindFirstChild("Head").Position - game.Workspace.CurrentCamera.CFrame.p).magnitude
                    local RAY = Ray.new(game.Workspace.CurrentCamera.CFrame.p, (Mouse.Hit.p - game.Workspace.CurrentCamera.CFrame.p).unit * DISTANCE)
                    local HIT,POS = game.Workspace:FindPartOnRay(RAY, game.Workspace)
                    local DIFF = math.floor((POS - AIM.Position).magnitude)
                    PLAYER_HOLD[v.Name .. i] = {}
                    PLAYER_HOLD[v.Name .. i].dist= DISTANCE
                    PLAYER_HOLD[v.Name .. i].plr = v
                    PLAYER_HOLD[v.Name .. i].diff = DIFF
                    table.insert(DISTANCES, DIFF)
                end
            end
        end
        
        if unpack(DISTANCES) == nil then
            return nil
        end
        
        local L_DISTANCE = math.floor(math.min(unpack(DISTANCES)))
        if L_DISTANCE > getgenv().AimRadius then
            return nil
        end
        
        for i, v in pairs(PLAYER_HOLD) do
            if v.diff == L_DISTANCE then
                return v.plr
            end
        end
        return nil
    end
    
    Mouse.KeyDown:Connect(function(a)
        if not (Uis:GetFocusedTextBox()) then 
            if a == AimlockKey and AimlockTarget == nil then
                pcall(function()
                    if MousePressed ~= true then MousePressed = true end 
                    local Target;Target = GetNearestTarget()
                    if Target ~= nil then 
                        AimlockTarget = Target
                    end
                end)
            elseif a == AimlockKey and AimlockTarget ~= nil then
                if AimlockTarget ~= nil then AimlockTarget = nil end
                if MousePressed ~= false then 
                    MousePressed = false 
                end
            end
        end
    end)
    
    RService.RenderStepped:Connect(function()
        if getgenv().ThirdPerson == true and getgenv().FirstPerson == true then 
            if (Camera.Focus.p - Camera.CoordinateFrame.p).Magnitude > 1 or (Camera.Focus.p - Camera.CoordinateFrame.p).Magnitude <= 1 then 
                CanNotify = true 
            else 
                CanNotify = false 
            end
        elseif getgenv().ThirdPerson == true and getgenv().FirstPerson == false then 
            if (Camera.Focus.p - Camera.CoordinateFrame.p).Magnitude > 1 then 
                CanNotify = true 
            else 
                CanNotify = false 
            end
        elseif getgenv().ThirdPerson == false and getgenv().FirstPerson == true then 
            if (Camera.Focus.p - Camera.CoordinateFrame.p).Magnitude <= 1 then 
                CanNotify = true 
            else 
                CanNotify = false 
            end
        end
        if Aimlock == true and MousePressed == true then 
            if AimlockTarget and AimlockTarget.Character and AimlockTarget.Character:FindFirstChild(getgenv().AimPart) then 
                if getgenv().FirstPerson == true then
                    if CanNotify == true then
                        if getgenv().PredictMovement == true then
                            if getgenv().Smoothness == true then
                                --// The part we're going to lerp/smoothen \\--
                                local Main = CF(Camera.CFrame.p, AimlockTarget.Character[getgenv().AimPart].Position + AimlockTarget.Character[getgenv().AimPart].Velocity/PredictionVelocity)
                                
                                --// Making it work \\--
                                Camera.CFrame = Camera.CFrame:Lerp(Main, getgenv().SmoothnessAmount, Enum.EasingStyle.Elastic, Enum.EasingDirection.InOut)
                            else
                                Camera.CFrame = CF(Camera.CFrame.p, AimlockTarget.Character[getgenv().AimPart].Position + AimlockTarget.Character[getgenv().AimPart].Velocity/PredictionVelocity)
                            end
                        elseif getgenv().PredictMovement == false then 
                            if getgenv().Smoothness == true then
                                --// The part we're going to lerp/smoothen \\--
                                local Main = CF(Camera.CFrame.p, AimlockTarget.Character[getgenv().AimPart].Position)

                                --// Making it work \\--
                                Camera.CFrame = Camera.CFrame:Lerp(Main, getgenv().SmoothnessAmount, Enum.EasingStyle.Elastic, Enum.EasingDirection.InOut)
                            else
                                Camera.CFrame = CF(Camera.CFrame.p, AimlockTarget.Character[getgenv().AimPart].Position)
                            end
                        end
                    end
                end
            end
        end
         if CheckIfJumped == true then
       if AimlockTarget.Character.HuDDDDDDDDDDWmanoid.FloorMaterial == Enum.Material.Air then
    
           getgenv().AimPart = "HumanoidRootPart"
       else
         getgenv().AimPart = getgenv().OldAimPart

       end
    end
end)
					end,
				},
				{
					Name = "Cancel"
				}
			}
		})
	end,
})

sections.Playersect1:Button({
	Name = "😎Target strafe (z) 😎",
	Callback = function()
		Window:Dialog({
			Title = Window.Settings.Title,
			Description = "circle round ur ops",
			Buttons = {
				{
					Name = "Confirm",
					Callback = function()
						   --[[
    === Config Section ===
    Adjust these values to customize the script.
--]]

local CONFIG = {
    ToggleKey = Enum.KeyCode.Z,      -- Key to toggle strafing (now set to Z)
    TargetPart = "UpperTorso",       -- Part to strafe around ("Head", "UpperTorso", etc.)
    StrafeRadius = 27,               -- Distance to maintain from the target
    StrafeSpeed = 20,                -- Speed of strafing
    EnableNotifications = true       -- Show notifications in the output
}

--[[
    === Script Start ===
--]]

-- Services
local Players = game:GetService("Players")
local RunService = game:GetService("RunService")
local UserInputService = game:GetService("UserInputService")

-- Variables
local player = Players.LocalPlayer
local character = player.Character or player.CharacterAdded:Wait()
local humanoidRootPart = character:WaitForChild("HumanoidRootPart")
local target = nil
local isStrafing = false
local currentAngle = 0

-- Notify function
local function notify(message)
    if CONFIG.EnableNotifications then
        print(message)
    end
end

-- Find the closest target
local function findClosestTarget()
    local closestPlayer = nil
    local closestDistance = math.huge

    for _, otherPlayer in pairs(Players:GetPlayers()) do
        if otherPlayer ~= player and otherPlayer.Character and otherPlayer.Character:FindFirstChild(CONFIG.TargetPart) then
            local targetPart = otherPlayer.Character[CONFIG.TargetPart]
            local distance = (targetPart.Position - humanoidRootPart.Position).Magnitude

            if distance < closestDistance then
                closestDistance = distance
                closestPlayer = otherPlayer
            end
        end
    end

    return closestPlayer
end

-- Toggle strafing
local function toggleStrafing()
    isStrafing = not isStrafing

    if isStrafing then
        -- Find a target to strafe around
        local closestPlayer = findClosestTarget()

        if closestPlayer and closestPlayer.Character then
            target = closestPlayer.Character:FindFirstChild(CONFIG.TargetPart)
            notify("Target Strafe: Enabled on " .. closestPlayer.Name)
        else
            notify("Target Strafe: No valid target found.")
            isStrafing = false
        end
    else
        notify("Target Strafe: Disabled.")
        target = nil
    end
end

-- Update strafing motion
RunService.RenderStepped:Connect(function(deltaTime)
    if isStrafing and target and humanoidRootPart then
        -- Calculate new position based on circular motion
        currentAngle = currentAngle + CONFIG.StrafeSpeed * deltaTime
        local offsetX = math.cos(currentAngle) * CONFIG.StrafeRadius
        local offsetZ = math.sin(currentAngle) * CONFIG.StrafeRadius
        local targetPosition = target.Position + Vector3.new(offsetX, 0, offsetZ)

        -- Move character to calculated position
        humanoidRootPart.CFrame = CFrame.new(targetPosition, target.Position)
    end
end)

-- Keybind to toggle strafing
UserInputService.InputBegan:Connect(function(input, gameProcessed)
    if gameProcessed then return end

    if input.KeyCode == CONFIG.ToggleKey then
        toggleStrafing()
    end
end)
					end,
				},
				{
					Name = "Cancel"
				}
			}
		})
	end,
})


Window.onUnloaded(function()
	print("Unloaded!")
end)

tabs.Main:Select()
MacLib:LoadAutoLoadConfig()

sections.Playersect1:Button({
	Name = "cframe speed (f)",
	Callback = function()
		Window:Dialog({
			Title = Window.Settings.Title,
			Description = "op asf",
			Buttons = {
				{
					Name = "Confirm",
					Callback = function()
						local Players = game:GetService("Players")
local RunService = game:GetService("RunService")
local UserInputService = game:GetService("UserInputService")

-- Initialize variables
local lastPosition = nil
local lastTime = nil
local isSpeedEnabled = false
local Multiplier = 0.5  -- Lower value for slower speed (e.g., 0.5)

-- Function to calculate and apply CFrame speed
local function calculateCFrameSpeed()
    local character = Players.LocalPlayer.Character
    if not character or not character:FindFirstChild("HumanoidRootPart") then return end
    
    lastPosition = character.HumanoidRootPart.Position
    lastTime = tick()

    -- Update speed every frame
    RunService.Heartbeat:Connect(function()
        if not character or not character:FindFirstChild("HumanoidRootPart") then return end
        local currentPosition = character.HumanoidRootPart.Position
        local currentTime = tick()
        
        -- Calculate the distance traveled
        local distance = (currentPosition - lastPosition).Magnitude
        local timeDelta = currentTime - lastTime
        
        -- Calculate the speed (distance / time)
        local speed = distance / timeDelta

        -- Print the calculated speed in studs per second
        print("CFrame Speed: " .. speed .. " studs per second")
        
        -- Update the last known position and time for the next frame
        lastPosition = currentPosition
        lastTime = currentTime

        -- Apply speed to the character's movement (based on multiplier)
        if isSpeedEnabled then
            character.HumanoidRootPart.CFrame = character.HumanoidRootPart.CFrame + character.Humanoid.MoveDirection * Multiplier
        end
    end)
end

-- Listen for key input (F key)
UserInputService.InputBegan:Connect(function(input, gameProcessed)
    if gameProcessed then return end
    
    if input.KeyCode == Enum.KeyCode.F then
        -- Toggle speed on/off
        isSpeedEnabled = not isSpeedEnabled
        if isSpeedEnabled then
            -- Start calculating CFrame speed
            print("Speed enabled! Multiplier set to: " .. Multiplier)
            calculateCFrameSpeed()
        else
            -- Stop the speed when 'F' is released
            print("Speed disabled!")
        end
    end
end)

-- Function to set the speed multiplier manually
function setSpeed(value)
    Multiplier = value
    print("Speed multiplier set to: " .. Multiplier)
end

-- Example usage: Change the speed multiplier directly (You can call this function anywhere in the script)
setSpeed(0.5)  -- Set speed multiplier to 0.5 for slower speed

					end,
				},
				{
					Name = "Cancel"
				}
			}
		})
	end,
})


sections.Playersect1:Slider({
	Name = "fly inverted controls (x)",
	Default = 50,
	Minimum = 0,
	Maximum = 100,
	DisplayMethod = "speed",
	Precision = 0,
	Callback = function(Value)
		-- Fly Script - Press X to toggle fly, adjust speed with "[" and "]"

local player = game.Players.LocalPlayer
local mouse = player:GetMouse()

if workspace:FindFirstChild("FlyCore") then
    workspace.FlyCore:Destroy()
end

-- Create a core part for flying
local FlyCore = Instance.new("Part")
FlyCore.Name = "FlyCore"
FlyCore.Size = Vector3.new(0.05, 0.05, 0.05)
FlyCore.Parent = workspace
FlyCore.Anchored = false
FlyCore.CanCollide = false

local weld = Instance.new("Weld", FlyCore)
weld.Part0 = FlyCore
weld.Part1 = player.Character:WaitForChild("LowerTorso")
weld.C0 = CFrame.new(0, 0, 0)

local isFlying = false
local speed = (Value)
local maxSpeed = (Value)
local minSpeed = (Value)
local keys = { W = false, A = false, S = false, D = false }

local function toggleFly(state)
    local character = player.Character
    if not character then return end

    local bodyGyro = FlyCore:FindFirstChild("BodyGyro") or Instance.new("BodyGyro", FlyCore)
    local bodyPosition = FlyCore:FindFirstChild("BodyPosition") or Instance.new("BodyPosition", FlyCore)

    bodyGyro.MaxTorque = Vector3.new(9e9, 9e9, 9e9)
    bodyGyro.P = 1e5
    bodyPosition.MaxForce = Vector3.new(9e9, 9e9, 9e9)
    bodyPosition.P = 1e5

    if state then
        isFlying = true
        character.Humanoid.PlatformStand = true

        -- Fly loop
        game:GetService("RunService").Heartbeat:Connect(function()
            if not isFlying then return end

            local moveDir = Vector3.new(
                (keys.D and 1 or  0) - (keys.A and 1 or 0),
                0,
                (keys.W and -1 or 0) + (keys.S and 1 or 0)
            )

            local camera = workspace.CurrentCamera
            local moveVector = (camera.CFrame.RightVector * moveDir.X + camera.CFrame.LookVector * moveDir.Z).Unit

            if moveVector.Magnitude > 0 then
                bodyPosition.Position = FlyCore.Position + moveVector * speed
            else
                bodyPosition.Position = FlyCore.Position
            end

            bodyGyro.CFrame = camera.CFrame
        end)
    else
        isFlying = false
        bodyGyro:Destroy()
        bodyPosition:Destroy()
        character.Humanoid.PlatformStand = false
    end
end

-- Keybinds
mouse.KeyDown:Connect(function(key)
    key = key:upper()

    if key == "W" then
        keys.W = true
    elseif key == "A" then
        keys.A = true
    elseif key == "S" then
        keys.S = true
    elseif key == "D" then
        keys.D = true
    elseif key == "X" then
        toggleFly(not isFlying)
    elseif key == "[" then
        speed = math.max(speed - 1, minSpeed)
        print("Speed decreased to:", speed)
    elseif key == "]" then
        speed = math.min(speed + 1, maxSpeed)
        print("Speed increased to:", speed)
    end
end)

mouse.KeyUp:Connect(function(key)
    key = key:upper()

    if key == "W" then
        keys.W = false
    elseif key == "A" then
        keys.A = false
    elseif key == "S" then
        keys.S = false
    elseif key == "D" then
        keys.D = false
    end
end)

	end
}, "Slider")


sections.Visualsect1:Button({
	Name = "esp",
	Callback = function()
		Window:Dialog({
			Title = Window.Settings.Title,
			Description = "esp locate ur ops",
			Buttons = {
				{
					Name = "Confirm",
					Callback = function()
						--- Tut

local esp_settings = { ---- table for esp settings 
textsize = 20, -- Increased text size for better visibility
colour = 255,255,255
}

local gui = Instance.new("BillboardGui")
local esp = Instance.new("TextLabel",gui) ---- new instances to make the billboard gui and the textlabel

gui.Name = "Cracked esp"; ---- properties of the esp
gui.ResetOnSpawn = false
gui.AlwaysOnTop = true;
gui.LightInfluence = 0;
gui.Size = UDim2.new(2, 0, 2, 0); -- Adjusted size for better visibility
esp.BackgroundColor3 = Color3.fromRGB(255, 255, 255);
esp.Text = ""
esp.Size = UDim2.new(0.001, 0, 0.001, 0); -- Adjusted to match larger text size
esp.BorderSizePixel = 4;
esp.BorderColor3 = Color3.new(esp_settings.colour)
esp.BorderSizePixel = 0
esp.Font = "GothamSemibold"
esp.TextSize = esp_settings.textsize -- Adjusted text size
esp.TextColor3 = Color3.fromRGB(esp_settings.colour) -- text colour

game:GetService("RunService").RenderStepped:Connect(function() ---- loops faster than a while loop :)
for i,v in pairs (game:GetService("Players"):GetPlayers()) do
	if v ~= game:GetService("Players").LocalPlayer and v.Character.Head:FindFirstChild("Cracked esp")==nil  then -- craeting checks for team check, local player etc
		esp.Text = "{"..v.Name.."}"
		gui:Clone().Parent = v.Character.Head
	end
end
end)

					end,
				},
				{
					Name = "Cancel"
				}
			}
		})
	end,
})

sections.MainSection1:Button({
	Name = "aim assist for silent aim or normal (e)",
	Callback = function()
		Window:Dialog({
			Title = Window.Settings.Title,
			Description = "op asf 0_0",
			Buttons = {
				{
					Name = "Confirm",
					Callback = function()
						getgenv().RecurringPoint = "UpperTorso"
getgenv().Hitbox = "UpperTorso"
getgenv().Keybind = "e"
getgenv().AimbotStrengthAmount = 0.0335
getgenv().PredictionAmount = 10
getgenv().Radius = 25
getgenv().UsePrediction = true
getgenv().AimbotStrength = true
getgenv().FirstPerson = true
getgenv().ThirdPerson = true
getgenv().TeamCheck = false
getgenv().Enabled = true


-- // main script use with silent aim / / -- 

loadstring(game:HttpGet("https://raw.githubusercontent.com/tenaaki/GenericAimbot/main/v1.0.0"))()
					end,
				},
				{
					Name = "Cancel"
				}
			}
		})
	end,
})

sections.Main2:Button({
	Name = "Reslover",
	Callback = function()
		Window:Dialog({
			Title = Window.Settings.Title,
			Description = "op as HELL🤓",
			Buttons = {
				{
					Name = "Confirm",
					Callback = function()
						loadstring(game:HttpGet("https://raw.githubusercontent.com/mars2423/reslover/refs/heads/main/RESLOVER?token=GHSAT0AAAAAAC4QJ2XOQV52EJ6ZPDQ7CM6IZ3W5YYA"))()

					end,
				},
				{
					Name = "Cancel"
				}
			}
		})
	end,
})
