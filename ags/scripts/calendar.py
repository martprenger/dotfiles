import gi
gi.require_version('EDataServer', '1.2')
gi.require_version('ECal', '2.0')
from gi.repository import EDataServer, ECal

def get_calendar_events():
    # Initialize EDS
    EDataServer.Client.set_application_name("MyApp")

    # Create a calendar client
    source = EDataServer.Source.new("my-calendar-source")
    client = ECal.Client.new_sync(source, ECal.ClientSourceType.EVENTS)

    # Fetch events
    query = ECal.ComponentText.new("VEVENT")
    events = client.get_objects_sync(query, None)

    for event in events:
        print(event.get_summary())

if __name__ == "__main__":
    get_calendar_events()
