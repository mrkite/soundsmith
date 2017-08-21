/** Copyright 2017 Sean Kasun */

class Song {
  public name: string;
  public music: string;
  public wb: string;
}

class SoundSmith {
  private name: string;
  private player: Player | null = null;

  public async getSongList(path: string): Promise<Song[]> {
    return new Promise<Song[]>((resolve: (songs: Song[]) => void) => {
      const req: XMLHttpRequest = new XMLHttpRequest();
      req.open('GET', path, true);
      req.onload = () => {
        resolve(JSON.parse(req.responseText));
      };
      req.send(null);
    });
  }

  public async open(name: string, music: string, wb: string): Promise<void> {
    this.name = name;
    const loaded: HTMLElement | null = document.getElementById('loaded');
    if (loaded) {
      loaded.textContent = 'loading...';
    }
    const info: HTMLElement | null = document.getElementById('info');

    const song: Handle = new Handle(await this.load(music));
    const wavebank: Handle = new Handle(await this.load(wb));

    if (this.player) {
      this.player.stop();
    }
    this.player = new Player(song, wavebank, (cur: number, max: number) => {
      if (info) {
        if (max == 0) {
          info.textContent = 'none';
        } else {
          info.textContent = cur.toString(10) + ' / ' + max.toString(10);
        }
      }
    });

    if (loaded) {
      loaded.textContent = name;
    }

    const controls: HTMLElement | null = document.getElementById('controls');
    if (controls) {
      while (controls.firstChild) {
        controls.removeChild(controls.firstChild);
      }
      const stop: HTMLButtonElement = document.createElement('button');
      stop.textContent = '\u23f9';
      stop.addEventListener('click', () => {
        if (this.player) {
          this.player.stop();
        }
      });
      controls.appendChild(stop);
      const play: HTMLButtonElement = document.createElement('button');
      play.textContent = '\u25b6';
      play.addEventListener('click', () => {
        if (this.player) {
          this.player.play();
        }
      });
      controls.appendChild(play);
    }
  }

  private async load(file: string): Promise<Uint8Array> {
    return new Promise<Uint8Array>((resolve) => {
      const req: XMLHttpRequest = new XMLHttpRequest();
      req.open('GET', file, true);
      req.responseType = 'arraybuffer';

      req.onload = () => {
        if (req.response) {
          resolve(new Uint8Array(req.response));
        }
      };
      req.send(null);
    });
  }
}

document.addEventListener('DOMContentLoaded', async () => {
  const ss: SoundSmith = new SoundSmith();
  const songs: Song[] = await ss.getSongList('songs.json');
  const list: HTMLElement | null = document.getElementById('songlist');
  if (!list) {
    return;
  }
  for (const song of songs) {
    const row: HTMLElement = document.createElement('div');
    row.dataset.name = song.name;
    row.dataset.music = song.music;
    row.dataset.wb = song.wb;
    row.appendChild(document.createTextNode(song.name));
    row.addEventListener('click', async (event: MouseEvent) => {
      const target = event.target as HTMLElement;
      await ss.open(target.dataset.name as string,
                    target.dataset.music as string,
                    target.dataset.wb as string);
    });
    list.appendChild(row);
  }
});
