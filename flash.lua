import("core.project.project")


function main()
    local target = project.target("app")
    local binOut = string.gsub(target:targetfile(), ".ihx", ".bin")    
    os.exec("wecan usb dfu")
    os.exec("wecan flash ./"..binOut)
end