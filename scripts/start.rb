require 'orocos'
require 'readline'
include Orocos


## Initialize orocos ##
Orocos.initialize

## Execute the task 'messages::Producer' ##
Orocos.run 'inclinometer_solar2::Task' => 'inclinometer_solar2' do
  ## Get the task context##
  driver = Orocos.name_service.get 'inclinometer_solar2'

  ## Configure the task
  driver.configure
  
  ## Start the task ##
  driver.start

  Readline::readline("Press Enter to exit\n") do
    end

end
