import trio
from user_interface.main_ui import MainUi


app = MainUi()
trio.run(app.async_run, 'trio')
