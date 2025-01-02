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

sections.MainSection1:Toggle({
	Name = "anti lock RESLOVER",
	Default = false,
	Callback = function(value)
		Window:Notify({
			Title = Window.Settings.Title,
			Description = (value and "Enabled " or "Disabled ") .. "Toggle"
		})
	end,
}, "Toggle")

--FIXED RESOLVER NOW no more game crash and lag and frame drops
([[This file was protected with MoonSec V3 by Federal#9999]]):gsub('.+', (function(a) _jdDOQWOGGdFP = a; end)); return(function(f,...)local u;local o;local a;local d;local t;local r;local e=24915;local n=0;local l={};while n<644 do n=n+1;while n<0x390 and e%0x2a5e<0x152f do n=n+1 e=(e*262)%43041 local h=n+e if(e%0x2b70)<0x15b8 then e=(e*0x253)%0x4921 while n<0x396 and e%0x3e2e<0x1f17 do n=n+1 e=(e-178)%26913 local r=n+e if(e%0x10f2)<=0x879 then e=(e+0xc6)%0x45dd local e=57752 if not l[e]then l[e]=0x1 t=function(l)local e=0x01 local function n(n)e=e+n return l:sub(e-n,e-0x01)end while true do local l=n(0x01)if(l=="\5")then break end local e=o.byte(n(0x01))local e=n(e)if l=="\2"then e=a.xrulurqW(e)elseif l=="\3"then e=e~="\0"elseif l=="\6"then d[e]=function(n,e)return f(8,nil,f,e,n)end elseif l=="\4"then e=d[e]elseif l=="\0"then e=d[e][n(o.byte(n(0x01)))];end local n=n(0x08)a[n]=e end end end elseif e%2~=0 then e=(e-0xb6)%0x8226 local e=53381 if not l[e]then l[e]=0x1 end else e=(e+0x2fe)%0x9bf2 n=n+1 local e=28902 if not l[e]then l[e]=0x1 end end end elseif e%2~=0 then e=(e*0x3fd)%0x4605 while n<0x1b2 and e%0x1896<0xc4b do n=n+1 e=(e*27)%7641 local t=n+e if(e%0xf10)<0x788 then e=(e+0xf6)%0x4c8d local e=829 if not l[e]then l[e]=0x1 u=tonumber;end elseif e%2~=0 then e=(e-0x56)%0x3cde local e=73629 if not l[e]then l[e]=0x1 d=(not d)and _ENV or d;end else e=(e*0x1ff)%0x9af0 n=n+1 local e=32702 if not l[e]then l[e]=0x1 r="\4\8\116\111\110\117\109\98\101\114\120\114\117\108\117\114\113\87\0\6\115\116\114\105\110\103\4\99\104\97\114\66\98\73\87\103\76\117\104\0\6\115\116\114\105\110\103\3\115\117\98\102\80\100\67\81\72\105\77\0\6\115\116\114\105\110\103\4\98\121\116\101\95\117\75\119\110\103\70\104\0\5\116\97\98\108\101\6\99\111\110\99\97\116\106\109\99\82\109\66\73\113\0\5\116\97\98\108\101\6\105\110\115\101\114\116\97\71\106\86\113\101\109\105\5";end end end else e=(e*0x6a)%0x9399 n=n+1 while n<0x2c4 and e%0x4dd0<0x26e8 do n=n+1 e=(e*393)%11025 local t=n+e if(e%0x2860)<=0x1430 then e=(e-0x35e)%0x2e6f local e=44345 if not l[e]then l[e]=0x1 o=string;end elseif e%2~=0 then e=(e-0x1d3)%0x1ea1 local e=97921 if not l[e]then l[e]=0x1 d=getfenv and getfenv();end else e=(e+0x22b)%0x425a n=n+1 local e=53037 if not l[e]then l[e]=0x1 a={};end end end end end e=(e-417)%10380 end t(r);local e={};for n=0x0,0xff do local l=a.BbIWgLuh(n);e[n]=l;e[l]=n;end local function h(n)return e[n];end local h=(function(r,o)local f,l=0x01,0x10 local n={{},{},{}}local d=-0x01 local e=0x01 local t=r while true do n[0x03][a.fPdCQHiM(o,e,(function()e=f+e return e-0x01 end)())]=(function()d=d+0x01 return d end)()if d==(0x0f)then d=""l=0x000 break end end local d=#o while e<d+0x01 do n[0x02][l]=a.fPdCQHiM(o,e,(function()e=f+e return e-0x01 end)())l=l+0x01 if l%0x02==0x00 then l=0x00 a.aGjVqemi(n[0x01],(h((((n[0x03][n[0x02][0x00]]or 0x00)*0x10)+(n[0x03][n[0x02][0x01]]or 0x00)+t)%0x100)));t=r+t;end end return a.jmcRmBIq(n[0x01])end);t(h(56,"a,6(^>G)y-S&:9W :9"));t(h(4,"sMTow^hLE>VO4f.dd4d.hLhw^.^M^TwL.Bo4w>ofo4MTMoT^TdMOM.#odoV4V>MJddd>F&d4dO44.f44fwfOO^f^hfhffwfT4^4h4E4VO^4T>wOE>hV3EooioT>O>E>TE^EhLOM^L>h>LEhohwhho4^hoE^ ^>TTwofEfEofTfo4T44^TEM4M>TEM4dLdOdnxhDhdOffWoE4>vdo.M.4.Mf^.b4>fE4MO.4wO>4^VhOV>.>E>MEOELowooL.E>Eo>bELEhwohfLE^fhT^f^f^L^.dF.4^OwMw^w4wLwwoTooM4owMwdOOhOM.^MdqoMMdMMAdff^4dE4E4dw.O.O.E.Tf^fh4OV4OkVoVE4VVwV.Efw-wMV4>^>T>EEfTV>^EVEEL^LoLL^dwf^D^Thdw>ow^E.4.V^^wVwEo^oooLoToTTLbKT4T4CwdGV4V>Mp,.iM)T2w4...f..w.dfq.O4dLgh.fL4^4EOfOL4wVMO.Oo>MVEEELOEET4T4>MEM>DEgM>LhLELLLoLT^(oVwOwLhMTVw>T>.M"));local e=(-1136+(function()local o,e=0,1;(function(d,l,e,n)n(d(e,e,n,e)and l(e,e,l,d),l(n,e,l,e),n(e,e and d,e,n),l(n,n,d,n))end)(function(l,n,t,d)if o>210 then return t end o=o+1 e=(e*853)%35187 if(e%1520)>=760 then return d(l(d,n,t,l),d(t,n,l and l,n),d(d,t,n,l)and l(n and n,n,d,l),d(t,n,n,d and l))else return n end return l end,function(d,t,n,l)if o>176 then return n end o=o+1 e=(e-140)%38998 if(e%1522)>761 then e=(e-789)%15437 return n else return t(n(d,l,n,d),d(n and n,n,n,d),t(l,l and l,n,l),t(t,t,l and l,l and d))end return n(t(l,n,n and l,l),t(t and l,l,n and t,t),t(l,t,l,d),d(d,d,n and n,d)and t(d,d,d,d))end,function(t,n,d,l)if o>297 then return n end o=o+1 e=(e-617)%40891 if(e%1032)>516 then e=(e*620)%28775 return n else return n(l(d,l,d,d),n(t,t,d,t),l(n,n,n,n),l(t and d,d,t,l)and n(d,d,t,d))end return t(l(l,d,n,l),n(t and t,l and l,n,l),d(d,l,n,l and n),t(d,l,t and n,t))end,function(d,t,l,n)if o>388 then return n end o=o+1 e=(e*719)%1544 if(e%1574)<787 then return l(d(l and t,t,l,t and n),t(l and t,d,n,d),t(l and d,n,l,d)and n(n,n,d,d),n(d,l,l,n))else return n end return l end)return e;end)())local ne=(getfenv)or(function()return _ENV end);local c=a.jngDtxTD or a.WIPVwUDl;local r=4;local t=3;local d=2;local le=1;local function ee(b,...)local s=h(e,"EV?A>Yx; =*{I.8#>Y;>*88 ?Yx0=x.aC*{{.#?Vxx?#=.*z.*V>*?#(?{x#Yx.xVAY0 A; g=?.;=x58*?xY.=II;##>*;Y*8*>AYxV*x.>Ix?. =IA#IV{x;=#=x-xV.>>IdVV#?Y?*{8>V#xx #.>IYVY># =IAI;V;A ;?*IAA #I=k??Vx.*Y.{(=x>=II.TIA# Y=>8#?>Y8==.I8=Yx=:I =A.>S>A8; #=YV=*{A##>x >{V8Y?V#=A;x**>.8Y{IV#*A>xY=.8 {V#Y??YI=x?#;>* I?h;>A A{Y8;?V; =>. IY%VAx;%**Y> V{=#8A X=>=;*{>88;_I;#.>  >*I8=V#xIAY;x*x8pV**xjAAxYY*V8 ?xYA ;IA==.?MI>x c{*#>V8*;*Y83VxYR *?{Y#*Y.;*#8x?<Y*=YI83 >?;#{{#T?*x>j8A{;A{ #?IV#*A>x8{Y8?VIYx=A.A%>A8; #YY> ;.?#{A; ?*.#>{#MIASx**>V# {IY#VAAx?*x8.#*YV=lIV#;>?xM*=8*?;YY=Y.*V=..V{>8  I?>I*?.V?A>==4I{=Y.T+x>s;*V{>#=YI;=#..Vn>* >V>Y.=Y8wVYY?>.Y;==I w?AI{.VYY8x;IxjVA8;i{ 8Y? #;AAx *?.I x{V#AAx;VA{;Y*I8x?FI #=>Ys{Y?;I{x#O;?.=O{A= y{{8#?>>I*A..VIA?;.I S>I., A8; {?A* ;I.##.;V=>  ?{I>?=#I.5Y>*x {88.A#xY*I;;{x8 ??YI8IAY;x{A8V?Vxx*Yx;*h.*V>>8  I?#IAx;K**8>V8Y {>IIWx>S II;88? x?*A.xVJ>*=xIj# AAxI**8dV*Y>*8.As?A.;x{V8*?;Y8{ 8x3I>; l{{#>A>x *?#?VxYV *Ix#8A ;?*I#V?TY*=>I8H >>;I{*#Y?*x>=8#;V?>. x8RWIA>;A* 8xVIxy=p.IyIA8;8{?#H?xx_=*#>?=>   {I#IA1x.*>#8VIY?=?IxmxA*;#*8o A.YI=I.HV9>>  { # > xx*Y.*?A>8 =I?0?Ax;>I?8>V8Y *VIIT;>N;8II88? x?{{.xVV>**>.F# A;xI**8}V{Y>*8..a?>V;x{Y8*?.Y8**.=%I>I %{##>?8x I?#gVxYx *I*#8>N;?{8#??bxV=>.{5 >?;II #;?*xI=88YV?>I x.?VxA>;;* 8#VIYx=NI*V>A8;8{?#Y?xx?=*8>A#>  ;{I5?Av;i*>#m?;Y?=?Ix:YA*;>*8c A YI=I./VJ>> x{ F>A.xx*;.*?V>8  I?X8A;;w{?8>?{Y =?IIV >.;*{.88AYx?=I.xVrYk >I># A{xI* 8f?*x? 8I.O?A8;x{x8*?*;.= .?)I>. }{{#>ALx *x#>VxY5 *I{#8A=;?*I##?,Y*=>I#a >?;I{x#>?*x>=88*>?>I xIS#{A>x8* 8>>*Yx=VI*6>A8; {?8IA*xT=*.>VS>  A{I#x>=x**>.8V=Y? IIxcIA*;>*88{?IYI=x.GY.{ .#?*xx=V. 8;>#;.>#??Y{=YI#c=>A{.Y.Y{=;IISx>jI8V.x?=>I;=..xVB>* >{8# Y?*I*=8>V*Y> 8VIx;{>8*{A#V?>Y8= ?Y;V{*IA?=xx=Ax{*x.IVxY4#V?Yx{=.;Y{>8x?9Y*. >A;**A#WV#Y#= x;{x. V?>I8I?=;?==.?I >8;.{.{q>VxI*A8x.?xY=Y.Y{*>;;x{;#VAt#=A>x**>.8 #{A#YA*UAA#;>*88 x**V8##V?{>; 8{ #??I{=TY> ; =I#;AxxY=I.=m.>Y=?IV^VA*Nx>Q;*{>88AYx?=I.x??xg >{8# AIxI*x8!?IYY 8I=J?A8;x{m8*?>;A= .?GI>  3{{#>>lx.*?.IVxY; *I>#8Y ;I*I8x?-Y*=>I#s x? .{x#r?*x>=8.8V?Y8*VIs#IA>;** 8?VIYx=xI*7;A8; {?8#?x=d* .>VV>  Y{IsVAg=*{#.8V{Y?=VIxS=A**>{.8 ?YYI=8.MP8>>;8{8#??Ixx*A.*VY>8  .*#IAx;M*{8>V8Y =8IIbx>-;.{888? x?8#>*;V{I# ?Ax*;=8Vd#8AV8Y> 8I Yx*V88?>8.? Y8= .? A*;8=?8#;A?x *?.I;.{V#;?=<V>?;?*I8x YI #8A. Vx?8;V#Y8=Vx;*A. V?>I.*?=x8*6.A*{#>VIYx=3A;xY*?...?>8=# _uY>x>?{{8..#?*x>*s. 8V? Y? IIxYA=#8?V?Ax=V.f##Ax;A*;.#?IY{={.>*A8?V>>8  cx;V* .VV8>. .Ix=AII9x>p;*{>88> *?=#..Vy>* >VVY.*x*#VYY?;#YY? xV={.Y)#>=IAxAY8= .?fI>x .{*#>?8;*{ .IVxYl .I>#8A  >{Y8x?VY**)I8y >?;I{=#N?*x>*K. VA>I= .V#*A>x8*I8?VIYx{q.YB>A8; {?8I?;x-{*8?P8>  ?{I#xA{x*{x#AV Y> II8D1A*;>*888??Y#=x.qB*>;;88 %&?Ix=*N8)V>YY  #?VYAx;A**8xV8Y.=?#IV#>2;.{>#;? xI=I.xV?>* >{8#{A?x.*x8j?VY> 8I OAAI;x{,8*A.Y8= .?%I;V T{*#>?#x *?.I? YY *I>#8A{;?*I8xA?Y8=>I8v > ;I{x#&Y^;==8. V?Y? xIV#*Axx8*I#*VIYx=).P}>A#; {x4>?xx7=*.{(8>= ?{In#A2x**>.#V Y? I. A4A*;>*88#??YI=x.?A >>;#{ #>?Ixx*_.*VY>8  I?#8Ax;V**#x?=Y =?IIO;>!;*{>rj>Vx?=..xV*>* >{8# >8xI*x8rVIY> #I V>>A;x{v8*?{Y8= .?a8;> z{{#>?#x *?.IVxxV *I>#8A*;?*.8xA?Y8=>I82 >.;I{x#F>*x#=8. V?>I xI>#*>x x* 8>VIY#=nI*R>A8;*{?8I?xx?=*.xQ8x  *{I#;AFx**>8xV ;?=YIxyVA*;Y*88.??Y8I>.u(.>>;8{ #??IxxI#.*VY>8 {I?#.Ax;gI>8>V8Y =AIIsx>v");local n=0;a.oDiLXcAe(function()a.stfkXtXC()n=n+1 end)local function e(l,e)if e then return n end;n=l+n;end local l,n,h=f(0,f,e,s,a._uKwngFh);local function o()local n,l=a._uKwngFh(s,e(1,3),e(5,6)+2);e(2);return(l*256)+n;end;local k=true;local k=0 local function j()local e=n();local n=n();local t=1;local d=(l(n,1,20)*(2^32))+e;local e=l(n,21,31);local n=((-1)^l(n,32));if(e==0)then if(d==k)then return n*0;else e=1;t=0;end;elseif(e==2047)then return(d==0)and(n*(1/0))or(n*(0/0));end;return a.OWPjngMw(n,e-1023)*(t+(d/(2^52)));end;local g=n;local function p(n)local l;if(not n)then n=g();if(n==0)then return'';end;end;l=a.fPdCQHiM(s,e(1,3),e(5,6)+n-1);e(n)local e=""for n=(1+k),#l do e=e..a.fPdCQHiM(l,n,n)end return e;end;local k=#a.LTKTzXfI(u('\49.\48'))~=1 local e=n;local function z(...)return{...},a.UvoQlPGX('#',...)end local function m()local u={};local c={};local e={};local s={u,c,nil,e};local e=n()local f={}for d=1,e do local l=h();local e;if(l==2)then e=(h()~=#{});elseif(l==1)then local n=j();if k and a.nHfLhuBg(a.LTKTzXfI(n),'.(\48+)$')then n=a.TBWWuBeI(n);end e=n;elseif(l==3)then e=p();end;f[d]=e;end;for e=1,n()do c[e-(#{1})]=m();end;s[3]=h();for c=1,n()do local e=h();if(l(e,1,1)==0)then local a=l(e,2,3);local h=l(e,4,6);local e={o(),o(),nil,nil};if(a==0)then e[t]=o();e[r]=o();elseif(a==#{1})then e[t]=n();elseif(a==b[2])then e[t]=n()-(2^16)elseif(a==b[3])then e[t]=n()-(2^16)e[r]=o();end;if(l(h,1,1)==1)then e[d]=f[e[d]]end if(l(h,2,2)==1)then e[t]=f[e[t]]end if(l(h,3,3)==1)then e[r]=f[e[r]]end u[c]=e;end end;return s;end;local function ee(l,n,e)local d=n;local d=e;return u(a.nHfLhuBg(a.nHfLhuBg(({a.oDiLXcAe(l)})[2],n),e))end local function g(k,e,h)local function ne(...)local o,p,s,m,b,n,u,_,j,y,ee,l;local e=0;while-1<e do if e<3 then if 1>e then o=f(6,28,1,14,k);p=f(6,71,2,8,k);else if-3<=e then repeat if 1<e then n=-41;u=-1;break;end;s=f(6,44,3,24,k);b=z m=0;until true;else s=f(6,44,3,24,k);b=z m=0;end end else if 5<=e then if e<6 then l=f(7);else e=-2;end else if-1~=e then repeat if e<4 then _={};j={...};break;end;y=a.UvoQlPGX('#',...)-1;ee={};until true;else _={};j={...};end end end e=e+1;end;for e=0,y do if(e>=s)then _[e-s]=j[e+1];else l[e]=j[e+1];end;end;local e=y-s+1 local e;local f;local function a(...)while true do end end while true do if n<-40 then n=n+42 end e=o[n];f=e[le];if 25>=f then if f>=13 then if f<19 then if f>15 then if f<17 then local d=e[d]local t={l[d](c(l,d+1,u))};local n=0;for e=d,e[r]do n=n+1;l[e]=t[n];end else if 18~=f then local f,a;for u=0,6 do if u<3 then if 1<=u then if u>-1 then repeat if 1<u then f=e[d];a=l[e[t]];l[f+1]=a;l[f]=a[e[r]];n=n+1;e=o[n];break;end;l[e[d]]=h[e[t]];n=n+1;e=o[n];until true;else f=e[d];a=l[e[t]];l[f+1]=a;l[f]=a[e[r]];n=n+1;e=o[n];end else f=e[d]l[f](l[f+1])n=n+1;e=o[n];end else if u<5 then if 4~=u then l(e[d],e[t]);n=n+1;e=o[n];else f=e[d]l[f]=l[f](c(l,f+1,e[t]))n=n+1;e=o[n];end else if 2<u then for h=24,64 do if u~=5 then f=e[d];a=l[e[t]];l[f+1]=a;l[f]=a[e[r]];break;end;l[e[d]]=l[e[t]][e[r]];n=n+1;e=o[n];break;end;else f=e[d];a=l[e[t]];l[f+1]=a;l[f]=a[e[r]];end end end end else l[e[d]]=l[e[t]][e[r]];end end else if f<=13 then l[e[d]][e[t]]=l[e[r]];else if 10~=f then for a=13,64 do if f>14 then local a;for f=0,6 do if f<3 then if f<=0 then l[e[d]]=h[e[t]];n=n+1;e=o[n];else if-3<=f then repeat if 2~=f then l[e[d]]=l[e[t]][e[r]];n=n+1;e=o[n];break;end;l(e[d],e[t]);n=n+1;e=o[n];until true;else l[e[d]]=l[e[t]][e[r]];n=n+1;e=o[n];end end else if 4>=f then if 3==f then l(e[d],e[t]);n=n+1;e=o[n];else l(e[d],e[t]);n=n+1;e=o[n];end else if 1<=f then for h=32,90 do if 5<f then l[e[d]][e[t]]=l[e[r]];break;end;a=e[d]l[a]=l[a](c(l,a+1,e[t]))n=n+1;e=o[n];break;end;else l[e[d]][e[t]]=l[e[r]];end end end end break;end;local f;l[e[d]][e[t]]=e[r];n=n+1;e=o[n];l[e[d]][e[t]]=e[r];n=n+1;e=o[n];l[e[d]][e[t]]=e[r];n=n+1;e=o[n];f=e[d]l[f](c(l,f+1,e[t]))n=n+1;e=o[n];do return end;break;end;else local f;l[e[d]][e[t]]=e[r];n=n+1;e=o[n];l[e[d]][e[t]]=e[r];n=n+1;e=o[n];l[e[d]][e[t]]=e[r];n=n+1;e=o[n];f=e[d]l[f](c(l,f+1,e[t]))n=n+1;e=o[n];do return end;end end end else if 22>f then if f>19 then if f>16 then repeat if f<21 then local e=e[d]l[e](l[e+1])break;end;local a;for f=0,6 do if f<3 then if 1<=f then if f~=2 then l[e[d]]=h[e[t]];n=n+1;e=o[n];else l[e[d]]=l[e[t]][e[r]];n=n+1;e=o[n];end else l[e[d]]=l[e[t]][e[r]];n=n+1;e=o[n];end else if f<=4 then if f>2 then for r=25,59 do if f>3 then l(e[d],e[t]);n=n+1;e=o[n];break;end;l(e[d],e[t]);n=n+1;e=o[n];break;end;else l(e[d],e[t]);n=n+1;e=o[n];end else if 4<f then repeat if 6~=f then l(e[d],e[t]);n=n+1;e=o[n];break;end;a=e[d]l[a]=l[a](c(l,a+1,e[t]))until true;else l(e[d],e[t]);n=n+1;e=o[n];end end end end until true;else local e=e[d]l[e](l[e+1])end else local f,g,s,p,a,k;for s=0,6 do if 3<=s then if s>=5 then if s~=3 then for h=32,59 do if s~=6 then f=e[d]k={l[f](c(l,f+1,u))};a=0;for e=f,e[r]do a=a+1;l[e]=k[a];end n=n+1;e=o[n];break;end;n=e[t];break;end;else n=e[t];end else if 1~=s then for h=38,77 do if s~=4 then f=e[d];g=l[e[t]];l[f+1]=g;l[f]=g[e[r]];n=n+1;e=o[n];break;end;f=e[d]k,p=b(l[f](l[f+1]))u=p+f-1 a=0;for e=f,u do a=a+1;l[e]=k[a];end;n=n+1;e=o[n];break;end;else f=e[d]k,p=b(l[f](l[f+1]))u=p+f-1 a=0;for e=f,u do a=a+1;l[e]=k[a];end;n=n+1;e=o[n];end end else if 1>s then l[e[d]]=h[e[t]];n=n+1;e=o[n];else if 1<s then l[e[d]]=l[e[t]][e[r]];n=n+1;e=o[n];else l[e[d]]=h[e[t]];n=n+1;e=o[n];end end end end end else if f>=24 then if 21~=f then repeat if f~=25 then n=e[t];break;end;do return end;until true;else do return end;end else if f>19 then for a=29,78 do if f<23 then local f,c;for a=0,6 do if 3>a then if a>0 then if-2<a then for r=38,67 do if 1<a then f=e[d]l[f](l[f+1])n=n+1;e=o[n];break;end;l(e[d],e[t]);n=n+1;e=o[n];break;end;else f=e[d]l[f](l[f+1])n=n+1;e=o[n];end else l[e[d]]=h[e[t]];n=n+1;e=o[n];end else if 5<=a then if a>=2 then for h=13,72 do if 5~=a then l(e[d],e[t]);break;end;f=e[d];c=l[e[t]];l[f+1]=c;l[f]=c[e[r]];n=n+1;e=o[n];break;end;else l(e[d],e[t]);end else if a>1 then repeat if 4~=a then l[e[d]]=h[e[t]];n=n+1;e=o[n];break;end;l[e[d]]=l[e[t]][e[r]];n=n+1;e=o[n];until true;else l[e[d]]=h[e[t]];n=n+1;e=o[n];end end end end break;end;if(l[e[d]]==e[r])then n=n+1;else n=e[t];end;break;end;else local f,c;for a=0,6 do if 3>a then if a>0 then if-2<a then for r=38,67 do if 1<a then f=e[d]l[f](l[f+1])n=n+1;e=o[n];break;end;l(e[d],e[t]);n=n+1;e=o[n];break;end;else f=e[d]l[f](l[f+1])n=n+1;e=o[n];end else l[e[d]]=h[e[t]];n=n+1;e=o[n];end else if 5<=a then if a>=2 then for h=13,72 do if 5~=a then l(e[d],e[t]);break;end;f=e[d];c=l[e[t]];l[f+1]=c;l[f]=c[e[r]];n=n+1;e=o[n];break;end;else l(e[d],e[t]);end else if a>1 then repeat if 4~=a then l[e[d]]=h[e[t]];n=n+1;e=o[n];break;end;l[e[d]]=l[e[t]][e[r]];n=n+1;e=o[n];until true;else l[e[d]]=h[e[t]];n=n+1;e=o[n];end end end end end end end end else if 6<=f then if f<=8 then if f>6 then if f==7 then local e=e[d]local d,n=b(l[e](l[e+1]))u=n+e-1 local n=0;for e=e,u do n=n+1;l[e]=d[n];end;else for f=0,4 do if f<2 then if 0<f then l[e[d]]=l[e[t]][e[r]];n=n+1;e=o[n];else l[e[d]]=h[e[t]];n=n+1;e=o[n];end else if 3<=f then if f~=-1 then repeat if f~=4 then l[e[d]]=l[e[t]][e[r]];n=n+1;e=o[n];break;end;if(l[e[d]]==l[e[r]])then n=n+1;else n=e[t];end;until true;else l[e[d]]=l[e[t]][e[r]];n=n+1;e=o[n];end else l[e[d]]=l[e[t]][e[r]];n=n+1;e=o[n];end end end end else l[e[d]]={};end else if 11>f then if 9<f then l(e[d],e[t]);else l[e[d]]={};end else if f~=8 then repeat if 12~=f then h[e[t]]=l[e[d]];break;end;local e=e[d]l[e](l[e+1])until true;else local e=e[d]l[e](l[e+1])end end end else if f>2 then if 4<=f then if f>=0 then for n=11,63 do if f>4 then l[e[d]]=(e[t]~=0);break;end;l[e[d]]=l[e[t]][e[r]];break;end;else l[e[d]]=(e[t]~=0);end else do return end;end else if 1<=f then if-1<=f then repeat if 2>f then local f;for r=0,4 do if r>1 then if 3>r then l(e[d],e[t]);n=n+1;e=o[n];else if 0<r then for a=26,67 do if r>3 then l[e[d]]=h[e[t]];break;end;f=e[d]l[f](l[f+1])n=n+1;e=o[n];break;end;else f=e[d]l[f](l[f+1])n=n+1;e=o[n];end end else if-2<r then repeat if 0<r then l[e[d]]=h[e[t]];n=n+1;e=o[n];break;end;f=e[d]l[f](l[f+1])n=n+1;e=o[n];until true;else f=e[d]l[f](l[f+1])n=n+1;e=o[n];end end end break;end;local d=e[d];local f=e[r];local o=d+2 local d={l[d](l[d+1],l[o])};for e=1,f do l[o+e]=d[e];end;local d=d[1]if d then l[o]=d n=e[t];else n=n+1;end;until true;else local o=e[d];local f=e[r];local d=o+2 local o={l[o](l[o+1],l[d])};for e=1,f do l[d+e]=o[e];end;local o=o[1]if o then l[d]=o n=e[t];else n=n+1;end;end else local n=e[d]l[n]=l[n](c(l,n+1,e[t]))end end end end else if f>38 then if 45>f then if f<42 then if 39>=f then l(e[d],e[t]);else if 38<f then repeat if 40<f then local n=e[d]local t={l[n](c(l,n+1,u))};local d=0;for e=n,e[r]do d=d+1;l[e]=t[d];end break;end;l[e[d]][e[t]]=e[r];until true;else local d=e[d]local t={l[d](c(l,d+1,u))};local n=0;for e=d,e[r]do n=n+1;l[e]=t[n];end end end else if f>=43 then if 41<=f then repeat if 44>f then for f=0,3 do if 2>f then if f>=-3 then for r=39,76 do if 0<f then h[e[t]]=l[e[d]];n=n+1;e=o[n];break;end;l[e[d]]=(e[t]~=0);n=n+1;e=o[n];break;end;else h[e[t]]=l[e[d]];n=n+1;e=o[n];end else if 1<=f then repeat if f~=3 then l[e[d]]=h[e[t]];n=n+1;e=o[n];break;end;if(l[e[d]]==e[r])then n=n+1;else n=e[t];end;until true;else l[e[d]]=h[e[t]];n=n+1;e=o[n];end end end break;end;if(l[e[d]]==l[e[r]])then n=n+1;else n=e[t];end;until true;else if(l[e[d]]==l[e[r]])then n=n+1;else n=e[t];end;end else local f;l[e[d]][e[t]]=e[r];n=n+1;e=o[n];l[e[d]][e[t]]=e[r];n=n+1;e=o[n];l[e[d]][e[t]]=e[r];n=n+1;e=o[n];f=e[d]l[f](c(l,f+1,e[t]))n=n+1;e=o[n];do return end;end end else if f<48 then if 46<=f then if f~=44 then for r=49,88 do if 47>f then l[e[d]]=g(p[e[t]],nil,h);break;end;local f;f=e[d]l[f](c(l,f+1,e[t]))n=n+1;e=o[n];do return end;break;end;else l[e[d]]=g(p[e[t]],nil,h);end else l[e[d]]=(e[t]~=0);end else if f<50 then if f==48 then l[e[d]]=h[e[t]];else l[e[d]][e[t]]=l[e[r]];end else if f~=50 then l[e[d]]=h[e[t]];else local d=e[d];local n=l[e[t]];l[d+1]=n;l[d]=n[e[r]];end end end end else if 31<f then if 35>f then if 33>f then local d=e[d];local n=l[e[t]];l[d+1]=n;l[d]=n[e[r]];else if f~=29 then for n=26,87 do if f~=34 then local n=e[d]l[n]=l[n](c(l,n+1,e[t]))break;end;h[e[t]]=l[e[d]];break;end;else local n=e[d]l[n]=l[n](c(l,n+1,e[t]))end end else if f<37 then if 33<f then for o=30,73 do if 35~=f then if(l[e[d]]==e[r])then n=n+1;else n=e[t];end;break;end;if(l[e[d]]==l[e[r]])then n=n+1;else n=e[t];end;break;end;else if(l[e[d]]==l[e[r]])then n=n+1;else n=e[t];end;end else if 36<=f then repeat if f~=38 then local a,c;for f=0,6 do if 3<=f then if f<5 then if 4~=f then l[e[d]]=h[e[t]];n=n+1;e=o[n];else l[e[d]]=l[e[t]][e[r]];n=n+1;e=o[n];end else if 6>f then a=e[d];c=l[e[t]];l[a+1]=c;l[a]=c[e[r]];n=n+1;e=o[n];else l(e[d],e[t]);end end else if f<1 then l[e[d]]=h[e[t]];n=n+1;e=o[n];else if 1<f then a=e[d]l[a](l[a+1])n=n+1;e=o[n];else l(e[d],e[t]);n=n+1;e=o[n];end end end end break;end;l[e[d]][e[t]]=e[r];until true;else local a,c;for f=0,6 do if 3<=f then if f<5 then if 4~=f then l[e[d]]=h[e[t]];n=n+1;e=o[n];else l[e[d]]=l[e[t]][e[r]];n=n+1;e=o[n];end else if 6>f then a=e[d];c=l[e[t]];l[a+1]=c;l[a]=c[e[r]];n=n+1;e=o[n];else l(e[d],e[t]);end end else if f<1 then l[e[d]]=h[e[t]];n=n+1;e=o[n];else if 1<f then a=e[d]l[a](l[a+1])n=n+1;e=o[n];else l(e[d],e[t]);n=n+1;e=o[n];end end end end end end end else if f>28 then if 29<f then if f<31 then n=e[t];else local d=e[d];local f=e[r];local o=d+2 local d={l[d](l[d+1],l[o])};for e=1,f do l[o+e]=d[e];end;local d=d[1]if d then l[o]=d n=e[t];else n=n+1;end;end else l[e[d]]=g(p[e[t]],nil,h);end else if 27>f then local e=e[d]local d,n=b(l[e](l[e+1]))u=n+e-1 local n=0;for e=e,u do n=n+1;l[e]=d[n];end;else if 24<f then for n=39,89 do if 27<f then local n=e[d]l[n](c(l,n+1,e[t]))break;end;local n=e[d]l[n](c(l,n+1,e[t]))break;end;else local n=e[d]l[n](c(l,n+1,e[t]))end end end end end end n=1+n;end;end;return ne end;local t=0xff;local h={};local f=(1);local d='';(function(n)local l=n local o=0x00 local e=0x00 l={(function(d)if o>0x23 then return d end o=o+1 e=(e+0xb49-d)%0x22 return(e%0x03==0x2 and(function(l)if not n[l]then e=e+0x01 n[l]=(0x63);end return true end)'xOrgc'and l[0x2](0x2d3+d))or(e%0x03==0x0 and(function(l)if not n[l]then e=e+0x01 n[l]=(0xd2);end return true end)'uTkLW'and l[0x1](d+0x2c0))or(e%0x03==0x1 and(function(l)if not n[l]then e=e+0x01 n[l]=(0x99);end return true end)'VytMY'and l[0x3](d+0x91))or d end),(function(r)if o>0x2f then return r end o=o+1 e=(e+0x5fe-r)%0x15 return(e%0x03==0x1 and(function(l)if not n[l]then e=e+0x01 n[l]=(0xce);d={d..'\58 a',d};h[f]=m();f=f+((not a.JOescjSG)and 1 or 0);d[1]='\58'..d[1];t[2]=0xff;end return true end)'vTPGD'and l[0x2](0x37b+r))or(e%0x03==0x0 and(function(l)if not n[l]then e=e+0x01 n[l]=(0x32);end return true end)'TWMDd'and l[0x1](r+0x134))or(e%0x03==0x2 and(function(l)if not n[l]then e=e+0x01 n[l]=(0x88);t[2]=(t[2]*(ee(function()h()end,c(d))-ee(t[1],c(d))))+1;h[f]={};t=t[2];f=f+t;end return true end)'_rYaJ'and l[0x3](r+0x34f))or r end),(function(r)if o>0x24 then return r end o=o+1 e=(e+0x793-r)%0x3a return(e%0x03==0x2 and(function(l)if not n[l]then e=e+0x01 n[l]=(0x5e);end return true end)'PaAVo'and l[0x3](0x36e+r))or(e%0x03==0x0 and(function(l)if not n[l]then e=e+0x01 n[l]=(0xef);d='\37';t={function()t()end};d=d..'\100\43';end return true end)'QFSHd'and l[0x2](r+0x1e3))or(e%0x03==0x1 and(function(l)if not n[l]then e=e+0x01 n[l]=(0x1b);h[f]=ne();f=f+t;end return true end)'JArVt'and l[0x1](r+0x279))or r end)}l[0x3](0xcf1)end){};local e=g(c(h));return e(...);end return ee((function()local n={}local e=0x01;local l;if a.JOescjSG then l=a.JOescjSG(ee)else l=''end if a.nHfLhuBg(l,a.zizPxZhO)then e=e+0;else e=e+1;end n[e]=0x02;n[n[e]+0x01]=0x03;return n;end)(),...)end)((function(n,e,l,d,t,o)local o;if 3<n then if n<6 then if 5>n then local n=d;local d,t,o=t(2);do return function()local e,f,l,r=e(l,n(n,n),n(n,n)+3);n(4);return(r*d)+(l*t)+(f*o)+e;end;end;else local n=d;do return function()local e=e(l,n(n,n),n(n,n));n(1);return e;end;end;end else if 7<=n then if 6<=n then repeat if n>7 then do return l(n,nil,l);end break;end;do return setmetatable({},{['__\99\97\108\108']=function(e,t,l,d,n)if n then return e[n]elseif d then return e else e[t]=l end end})end until true;else do return setmetatable({},{['__\99\97\108\108']=function(e,l,d,t,n)if n then return e[n]elseif t then return e else e[l]=d end end})end end else do return t[l]end;end end else if n>=2 then if 0<n then for o=38,66 do if n~=3 then do return 16777216,65536,256 end;break;end;do return e(1),e(4,t,d,l,e),e(5,t,d,l)end;break;end;else do return e(1),e(4,t,d,l,e),e(5,t,d,l)end;end else if 1==n then do return function(n,e,l)if l then local e=(n/2^(e-1))%2^((l-1)-(e-1)+1);return e-e%1;else local e=2^(e-1);return(n%(e+e)>=e)and 1 or 0;end;end;end;else do return e(1),e(4,t,d,l,e),e(5,t,d,l)end;end end end end),...)

